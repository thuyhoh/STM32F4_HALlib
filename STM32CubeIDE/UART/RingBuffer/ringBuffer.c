#include "ringBuffer.h"

typedef struct ringBuffer_t {
    uint8_t *buffer; // Pointer to the buffer
    uint16_t head_index;   // Index of the next byte to be written
    uint16_t tail_index;   // Index of the next byte to be read
    uint16_t buffer_size;   // Size of the buffer
    uint16_t fill_size; 
} ringBuffer_t;

void ringBuffer_init(ringBuffer_t *ringBuffer,void *buffer, uint16_t size) {
    ringBuffer->tail_index = 0;
    ringBuffer->head_index = 0;  
    ringBuffer->fill_size = 0;

    ringBuffer->buffer_size = 0;
    ringBuffer->buffer = (uint8_t*)buffer;
}

void ringBuffer_put(ringBuffer_t *ringBuffer, uint8_t byte) {
    uint16_t next_tail_index;
    uint16_t next_head_index;

    ringBuffer->buffer[ringBuffer->tail_index] = byte;
    next_tail_index = (++ringBuffer->tail_index) % ringBuffer->buffer_size;
    ringBuffer->tail_index = next_tail_index;

    if(ringBuffer->fill_size == ringBuffer->buffer_size) {
        next_head_index = (++ringBuffer->head_index) % ringBuffer->buffer_size;
        ringBuffer->head_index = next_head_index;
    } else {    
        ringBuffer->fill_size++;
    }
}

void ringBuffer_get(ringBuffer_t *ringBuffer, uint8_t *byte) {
    uint16_t next_head_index;
    if(ringBuffer->fill_size == 0) {
        return;
    }

    *byte = ringBuffer->buffer[ringBuffer->head_index];
    ringBuffer->head_index = (++ringBuffer->head_index) % ringBuffer->buffer_size;
    ringBuffer->fill_size--;
}

bool ringBuffer_isEmpty(ringBuffer_t *ringBuffer) {
    return (ringBuffer->fill_size == 0);
}

bool ringBuffer_isFull(ringBuffer_t *ringBuffer) {
    return (ringBuffer->fill_size == ringBuffer->buffer_size);
}


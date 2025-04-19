#ifndef RINGBUFFER_H
#define RINGBUFFER_H
#include "string.h"
#include "stdint.h"
#include "stdlib.h"
#include "stdbool.h"
#include "stdio.h"

typedef struct ringBuffer_t {
    uint8_t *buffer; // Pointer to the buffer
    uint16_t head_index;   // Index of the next byte to be written
    uint16_t tail_index;   // Index of the next byte to be read
    uint16_t buffer_size;   // Size of the buffer
    uint16_t fill_size; 
} ringBuffer_t;

void ringBuffer_init(ringBuffer_t *ringBuffer,void *buffer, uint16_t size);

void ringBuffer_put(ringBuffer_t *ringBuffer, uint8_t byte);

void ringBuffer_get(ringBuffer_t *ringBuffer, uint8_t *byte);

bool ringBuffer_isEmpty(ringBuffer_t *ringBuffer);

bool ringBuffer_isFull(ringBuffer_t *ringBuffer) ;

#endif // RINGBUFFER_H

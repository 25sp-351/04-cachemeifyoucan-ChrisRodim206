#include "rodcut.h"

#define CACHE_SIZE 100

typedef struct {
    int key;
    int value;
} CacheEntry;

static CacheEntry cache[CACHE_SIZE];
static int current_index = 0;  // Tracks the next index to overwrite
static int cache_count = 0;    // Tracks the number of entries in cache

// Initialize the cache with invalid values
void cache_init() {
    for (int i = 0; i < CACHE_SIZE; i++) {
        cache[i].key = -1;
        cache[i].value = 0;
    }
    current_index = 0;
    cache_count = 0;
}

// Add a new entry or overwrite the oldest one in FIFO.
void cache_put(int key, int value) {
    if (cache_count < CACHE_SIZE) {
        // Insert new entry if space is available
        cache[cache_count].key = key;
        cache[cache_count].value = value;
        cache_count++;
    } else {
        // Overwrite the oldest entry
        cache[current_index].key = key;
        cache[current_index].value = value;
    }
    
    // Update the current index to the next one in a circular manner
    current_index = (current_index + 1) % CACHE_SIZE;
}

int cache_get(int key, int* value) {
    for (int i = 0; i < cache_count; i++) {
        if (cache[i].key == key) {
            *value = cache[i].value;
            return 1;
        }
    }
    return 0;  
}



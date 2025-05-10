#include "rodcut.h"

#define INVALID_KEY -1

static int cache_keys[CACHE_SIZE];
static int cache_values[CACHE_SIZE];
static int cache_access_times[CACHE_SIZE];
static int global_time = 0;

void cache_init() {
    for (int i = 0; i < CACHE_SIZE; ++i) {
        cache_keys[i] = INVALID_KEY;
        cache_access_times[i] = 0;
    }
}

int cache_get(int rod_length, int* out_value) {
    for (int i = 0; i < CACHE_SIZE; ++i) {
        if (cache_keys[i] == rod_length) {
            cache_access_times[i] = ++global_time;
            *out_value = cache_values[i];
            return 1;
        }
    }
    return 0;
}

void cache_put(int rod_length, int value) {
    int lru_index = -1;
    int oldest_time = global_time + 1;

    for (int i = 0; i < CACHE_SIZE; ++i) {
        if (cache_keys[i] == INVALID_KEY) {
            lru_index = i;
            break;
        }
        if (cache_access_times[i] < oldest_time) {
            oldest_time = cache_access_times[i];
            lru_index = i;
        }
    }

    cache_keys[lru_index] = rod_length;
    cache_values[lru_index] = value;
    cache_access_times[lru_index] = ++global_time;
}



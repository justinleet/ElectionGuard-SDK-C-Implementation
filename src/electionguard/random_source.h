#pragma once

#include "uint4096.h"
#include "bignum.h"

/* #undef HAVE_BCRYPTGENRANDOM */

// You should create one of these for each thread that may run.
typedef struct RandomSource_s *RandomSource;

enum RandomSource_status {
    RANDOM_SOURCE_SUCCESS,
    RANDOM_SOURCE_INSUFFICIENT_MEMORY,
    RANDOM_SOURCE_IO_ERROR
};

struct RandomSource_new_r {
    enum RandomSource_status status;
    RandomSource source;
};

struct RandomSource_new_r RandomSource_new(void);
void RandomSource_free(RandomSource source);

struct RandomSource_uniform_r {
    enum RandomSource_status status;
    uint4096 result;
};

// Uses rejection sampling to pick a number between 1 and modulus_default-1,
// inclusive.
struct RandomSource_uniform_r RandomSource_uniform(RandomSource source);
enum RandomSource_status RandomSource_uniform_o(RandomSource source, uint4096 out);
enum RandomSource_status RandomSource_uniform_bignum_o(mpz_t out, RandomSource source);

/*
 * Common code for the Ethereum Wallet format.
 *
 * This file takes replicated but common code, shared between the CPU
 * and the GPU formats, and places it into one common location.
 */

#include "formats.h"

#define FORMAT_TAG              "$ethereum$"
#define TAG_LENGTH              (sizeof(FORMAT_TAG) - 1)

typedef struct {
	uint32_t type;
	int N, r, p;
	int iterations;
	uint8_t salt[64];
	int saltlen;
	uint8_t ct[256];
	int ctlen;
} custom_salt;

extern struct fmt_tests ethereum_tests[];

// exported 'common' functions
int ethereum_common_valid(char *ciphertext, struct fmt_main *self);
void *ethereum_common_get_salt(char *ciphertext);
unsigned int ethereum_common_iteration_count(void *salt);

#include "lto.h"
#include "ledger_crypto.h"

#include <string.h>

void lto_secure_hash(const uint8_t *message, size_t message_len, uint8_t hash[32]) {
    blake2b_256(message, message_len, hash);
    sha_256(hash, 32, hash);
}

void lto_message_sign(const cx_ecfp_private_key_t *private_key, const unsigned char *message, const size_t message_size, ed25519_signature signature) {
    // ed25519 signature with the sha512 hashing
    cx_eddsa_sign(private_key, 0, CX_SHA512, message, message_size, NULL, 0, signature, 64, NULL);
}

// Build lto address from the ed25519 public key
void lto_public_key_to_address(const ed25519_public_key public_key, const unsigned char network_byte, char *output) {
    uint8_t public_key_hash[32];
    uint8_t address[26];
    uint8_t checksum[32];

    lto_secure_hash(public_key, 32, public_key_hash);

    // Prefix
    address[0] = 0x01;
    address[1] = network_byte;

    memcpy(&address[2], public_key_hash, 20);

    lto_secure_hash(address, 22, checksum);

    memcpy(&address[22], checksum, 4);

    size_t length = 36;
    b58enc(output, &length, address, 26);
}

void copy_in_reverse_order(void *to, const void *from, const size_t len) {
    uint8_t *dst = to;
    const uint8_t *src = from;

    for (unsigned i = 0; i < len; i++) {
        dst[i] = src[(len - 1) - i];
    }
}    

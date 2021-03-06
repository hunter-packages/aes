#ifndef _AES_H_
#define _AES_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// #define the macros below to 1/0 to enable/disable the mode of operation.
//
// AES_CBC enables AES encryption in CBC-mode of operation.
// AES_ECB enables the basic ECB 16-byte block algorithm. Both can be enabled simultaneously.

// The #ifndef-guard allows it to be configured before #include'ing or at compile time.
#ifndef AES_CBC
# define AES_CBC 1
#endif

#ifndef AES_ECB
  #define AES_ECB 1
#endif

#if defined(AES_ECB) && (AES_ECB == 1)

void AES_ECB_encrypt(const uint8_t* input, const uint8_t* key, uint8_t *output, const uint32_t length);
void AES_ECB_decrypt(const uint8_t* input, const uint8_t* key, uint8_t *output, const uint32_t length);

#endif // #if defined(AES_ECB) && (AES_ECB == !)


#if defined(AES_CBC) && (AES_CBC == 1)

void AES_CBC_encrypt_buffer(uint8_t* output, uint8_t* input, uint32_t length, const uint8_t* key, const uint8_t* iv);
void AES_CBC_decrypt_buffer(uint8_t* output, uint8_t* input, uint32_t length, const uint8_t* key, const uint8_t* iv);

#endif // #if defined(AES_CBC) && (AES_CBC == 1)

#ifdef __cplusplus
} // extern "C"
#endif

#endif //_AES_H_

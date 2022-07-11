/* libsodium: hmac_hmacsha512.c, v0.4.5 2014/04/16 */
/**
 * Copyright 2005,2007,2009 Colin Percival. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */
#ifndef LIBBITCOIN_SYSTEM_CRYPTO_EXTERNAL_HMACSHA256_HPP
#define LIBBITCOIN_SYSTEM_CRYPTO_EXTERNAL_HMACSHA256_HPP

#include <bitcoin/system/define.hpp>
#include <bitcoin/system/crypto/sha256_context.hpp>

#define HMACSHA256_DIGEST_LENGTH 32U

typedef struct HMACSHA256CTX
{
    bc::system::sha256::context ctx;
    bc::system::sha256::context ictx;
    bc::system::sha256::context octx;
} HMACSHA256CTX;

void HMACSHA256(const uint8_t* input, size_t length, const uint8_t* key,
    size_t key_length, uint8_t digest[HMACSHA256_DIGEST_LENGTH]) NOEXCEPT;

void HMACSHA256Final(HMACSHA256CTX* context,
    uint8_t digest[HMACSHA256_DIGEST_LENGTH]) NOEXCEPT;

void HMACSHA256Init(HMACSHA256CTX* context, const uint8_t* key,
    size_t key_length) NOEXCEPT;

void HMACSHA256Update(HMACSHA256CTX* context, const uint8_t* input,
    size_t length) NOEXCEPT;

#endif

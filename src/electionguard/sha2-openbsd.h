/*	$OpenBSD: sha2.h,v 1.4 2012/12/05 23:20:15 deraadt Exp $	*/

/*
 * FILE:	sha2.h
 * AUTHOR:	Aaron D. Gifford <me@aarongifford.com>
 *
 * Copyright (c) 2000-2001, Aaron D. Gifford
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTOR(S) ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTOR(S) BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * $From: sha2.h,v 1.1 2001/11/08 00:02:01 adg Exp adg $
 */

#ifndef _SHA2_H
#define _SHA2_H

#include <sys/param.h>
#include <string.h>
#include <stdint.h>

<<<<<<< HEAD
=======
#include <sys/cdefs.h>

>>>>>>> 488b7513dc61eb88fa7d7a306300ef07faca79ff
#define bzero(s, n) memset((s), 0, (n))
#define bcopy(s1, s2, n) memcpy((s2), (s1), (n))
#define NO_MEMSET_S true
#ifndef NO_MEMSET_S
#define explicit_bzero(s, n) memset_s((s), (n), 0, (n))
#else
#define explicit_bzero(s, n) force_memset((s), (n))
void force_memset(void *ptr, size_t len);
#endif

/*** SHA-256/384/512 Various Length Definitions ***********************/
#define SHA256_BLOCK_LENGTH		64
#define SHA256_DIGEST_LENGTH		32
#define SHA256_DIGEST_STRING_LENGTH	(SHA256_DIGEST_LENGTH * 2 + 1)
#define SHA384_BLOCK_LENGTH		128
#define SHA384_DIGEST_LENGTH		48
#define SHA384_DIGEST_STRING_LENGTH	(SHA384_DIGEST_LENGTH * 2 + 1)
#define SHA512_BLOCK_LENGTH		128
#define SHA512_DIGEST_LENGTH		64
#define SHA512_DIGEST_STRING_LENGTH	(SHA512_DIGEST_LENGTH * 2 + 1)


/*** SHA-256/384/512 Context Structure *******************************/
typedef struct _SHA2_CTX {
	union {
		uint32_t	st32[8];
		uint64_t	st64[8];
	} state;
	uint64_t	bitcount[2];
	uint8_t	buffer[SHA512_BLOCK_LENGTH];
} SHA2_CTX;

__BEGIN_DECLS
void SHA256Init(SHA2_CTX *);
#pragma GCC diagnostic ignored "-Wattributes"
void SHA256Update(SHA2_CTX *, const uint8_t *, size_t)
	__attribute__((__bounded__(__string__,2,3)));
void SHA256Final(uint8_t[SHA256_DIGEST_LENGTH], SHA2_CTX *)
	__attribute__((__bounded__(__minbytes__,1,SHA256_DIGEST_LENGTH)));

void SHA384Init(SHA2_CTX *);
void SHA384Update(SHA2_CTX *, const uint8_t *, size_t)
	__attribute__((__bounded__(__string__,2,3)));
void SHA384Final(uint8_t[SHA384_DIGEST_LENGTH], SHA2_CTX *)
	__attribute__((__bounded__(__minbytes__,1,SHA384_DIGEST_LENGTH)));

void SHA512Init(SHA2_CTX *);
void SHA512Update(SHA2_CTX *, const uint8_t *, size_t)
	__attribute__((__bounded__(__string__,2,3)));
void SHA512Final(uint8_t[SHA512_DIGEST_LENGTH], SHA2_CTX *)
	__attribute__((__bounded__(__minbytes__,1,SHA512_DIGEST_LENGTH)));
__END_DECLS

#endif /* _SHA2_H */

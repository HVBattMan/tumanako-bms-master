/**
 * \file crc.h
 * Functions and types for CRC checks.
 *
 * Generated on Fri Apr 23 23:04:33 2010,
 * by pycrc v0.7.5, http://www.tty1.net/pycrc/
 * using the configuration:
 *    Width        = 16
 *    Poly         = 0x1021
 *    XorIn        = 0xffff
 *    ReflectIn    = False
 *    XorOut       = 0x0000
 *    ReflectOut   = False
 *    Algorithm    = bit-by-bit-fast
 *****************************************************************************/
#ifndef __CRC_H__
#define __CRC_H__

#include <stdint.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * The definition of the used algorithm.
 *****************************************************************************/
#define CRC_ALGO_BIT_BY_BIT_FAST 1

/**
 * The type of the CRC values.
 *
 * This type must be big enough to contain at least 16 bits.
 *****************************************************************************/
typedef uint16_t crc_t;

/**
 * Calculate the initial crc value.
 *
 * \return     The initial crc value.
 *****************************************************************************/
static inline crc_t crc_init(void) {
	return 0xffff;
}

/**
 * Update the crc value with new data.
 *
 * \param crc      The current crc value.
 * \param data     Pointer to a buffer of \a data_len bytes.
 * \param data_len Number of bytes in the \a data buffer.
 * \return         The updated crc value.
 *****************************************************************************/
crc_t crc_update(crc_t crc, const unsigned char *data, size_t data_len);

/**
 * Calculate the final crc value.
 *
 * \param crc  The current crc value.
 * \return     The final crc value.
 *****************************************************************************/
static inline crc_t crc_finalize(crc_t crc) {
	return crc ^ 0x0000;
}

#ifdef __cplusplus
} /* closing brace for extern "C" */
#endif

#endif      /* __CRC_H__ */

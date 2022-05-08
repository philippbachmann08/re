/**
 * @file re_av1.c AV1 Open Bitstream Unit (OBU)
 *
 * Copyright (C) 2010 - 2022 Alfred E. Heggestad
 */


/* OBU (Open Bitstream Units) */

/*
 * OBU Header
 *
 *     0 1 2 3 4 5 6 7
 *    +-+-+-+-+-+-+-+-+
 *    |F| type  |X|S|-| (REQUIRED)
 *    +-+-+-+-+-+-+-+-+
 */
struct av1_obu_hdr {
	unsigned type:4;  /* type           */
	bool x;           /* extension flag */
	bool s;           /* has size field */
	size_t size;      /* payload size   */
};

int av1_leb128_encode(struct mbuf *mb, size_t value);
int av1_leb128_decode(struct mbuf *mb, size_t *value);
int av1_obu_encode(struct mbuf *mb, uint8_t type, bool has_size,
		   size_t len, const uint8_t *payload);
int av1_obu_decode(struct av1_obu_hdr *hdr, struct mbuf *mb);
int av1_obu_print(struct re_printf *pf, const struct av1_obu_hdr *hdr);
#ifndef __EMUL_LINE_PC_CMD_H__
#define __EMUL_LINE_PC_CMD_H__
///#include "calc_crc.h"

#define WR_CMD      0x1
#define RD_CMD      0x2
#define WR_RD_CMD   0x3

#define PUT_OUT     0x1
#define SET_OUT     0x2
#define CLR_OUT     0x3
#define GET_INP     0x4
extern uint8_t parse_cmd(uint8_t *ibuf,uint8_t len,uint8_t *obuf);

#endif

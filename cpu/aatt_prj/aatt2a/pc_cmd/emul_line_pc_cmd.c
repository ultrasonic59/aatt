#include <stdint.h>
#include "calc_crc.h"
#include "emul_line_pc_cmd.h"
///#include "calc_crc.h"
#include "baloo_emul_line_brd.h"

uint8_t check_cmd(uint8_t *ibuf,uint8_t len)
{
uint8_t rez=0;
uint16_t tmp;

if((ibuf==0)||(len<4))
    return 0;
tmp = Calc_CRC16(ibuf, len-2);
if((ibuf[len-2]==(uint8_t)tmp)&&(ibuf[len-1]==(uint8_t)(tmp>>8)))
  {
  rez=1;
  }
else
  rez=0;
return rez;
}
uint8_t wr_cmd(uint8_t *ibuf,uint8_t len,uint8_t *obuf)
{
uint8_t rez=0;
switch(ibuf[0])
  {
  case PUT_OUT:
     put_out_n(ibuf[3]);
     obuf[0]=ibuf[0];
     obuf[1]=1;   ///size
     obuf[2]=0;
     obuf[3]=ibuf[3];
     rez=4;
     break;
  case SET_OUT:
      set_out_n(ibuf[3]);
      obuf[0]=ibuf[0];
      obuf[1]=1;   ///size
      obuf[2]=0;
      obuf[3]=ibuf[3];
      rez=4;
     break;
  case CLR_OUT:
      clr_out_n(ibuf[3]);
      obuf[0]=ibuf[0];
      obuf[1]=1;   ///size
      obuf[2]=0;
      obuf[3]=ibuf[3];
      rez=4;
     break;
  }
return rez;

}
uint8_t rd_cmd(uint8_t *ibuf,uint8_t len,uint8_t *obuf)
{
uint8_t rez=0;
switch(ibuf[0])
  {
   case GET_INP:
       obuf[0]=ibuf[0];
       obuf[1]=1;   ///size
       obuf[2]=0;
       obuf[3]=get_inp();
       rez=4;
     break;
  }
return rez;
}

uint8_t parse_cmd(uint8_t *ibuf,uint8_t len,uint8_t *obuf)
{
uint16_t tmp;
uint8_t rez=0;
if((ibuf==0)||(obuf==0))
    return 0;
if(check_cmd(ibuf,len)==0)
   return 0;
switch(ibuf[0])
  {
  case WR_CMD:
      obuf[0]=ibuf[0];
      rez=wr_cmd(ibuf+1,len,obuf+1);
      rez++;
      tmp=Calc_CRC16(obuf, rez);
      obuf[rez++]=tmp&0xff;
      obuf[rez++]=(tmp>>8)&0xff;
     break;
  case RD_CMD:
      obuf[0]=ibuf[0];
      rez=rd_cmd(ibuf+1,len,obuf+1);
      rez++;
      tmp=Calc_CRC16(obuf, rez);
      obuf[rez++]=tmp&0xff;
      obuf[rez++]=(tmp>>8)&0xff;
     break;
  case WR_RD_CMD:
     break;
  }
////printf("\r\n parse_cmd:[%x][%x][%x]", ibuf[0],len,rez);

return rez;
}

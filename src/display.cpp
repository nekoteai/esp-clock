#include "U8g2lib.h"
U8G2_SSD1306_128X64_NONAME_1_SW_I2C u8g2(U8G2_R0,);
void display_test(){
    u8g2.begin();
    char m_str[3];
  strcpy(m_str, u8x8_u8toa(m, 2));
  u8g2.firstPage();
  do {
    u8g2.setFont(u8g2_font_logisoso62_tn);
    u8g2.drawStr(0,63,"9");
    u8g2.drawStr(33,63,":");
    u8g2.drawStr(50,63,m_str);
  } while ( u8g2.nextPage() );
  delay(1000);
  m++;
  if ( m == 60 )
    m = 0;
}

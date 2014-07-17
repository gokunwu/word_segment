/*
 * Transcode.h
 *
 *  Created on: 2014Äê7ÔÂ8ÈÕ
 *      Author: kunwu
 */

#ifndef TRANSCODE_H_
#define TRANSCODE_H_

#include <vector>
#include <string>
#include "Common.h"

class Transcode
{
public:
  Transcode();
  ~Transcode();
  void release();
  size_t getMemorySize();

  char *convertFromUSC2(const std::wstring &wstring_str,
                        size_t * pUnint_out_len,
                        EnumCharset EnumCharset_code);
  char *convertFromUSC2(const unsigned short * pUnshort_usc,
                        size_t unint_usc_len,
                        size_t * pUnint_outlen,
                        EnumCharset EnumCharset_code);
  size_t convertFromUSC2(const unsigned short  * pUnshort_src,
                        size_t unint_src_len,
                        char * pChar_dst,
                        size_t unint_dst_len,
                        EnumCharset EnumCharset_code);
  size_t convertUSC2ToGBK(const unsigned short * pUnshort_src,
                          size_t unint_src_len,
                          char * pChar_dst,
                          size_t unint_dst_len);
  size_t convertUSC2ToUTF8(const unsigned short * pUnshort_src,
                           size_t unint_src_len,
                           char * pChar_dst,
                           size_t unint_dst_len);

  unsigned short *convertToUSC2(const char *pChar_utf8,
                                size_t unint_utf8_len,
                                size_t *pUnint_usc2_len,
                                EnumCharset EnumCharset_code);
  size_t convertToUSC2(const char *pChar_src,
                       size_t unint_src_len,
                       unsigned short *pUnshort_dst,
                       size_t unint_dst_len,
                       EnumCharset EnumCharset_code);
  size_t convertGBKToUSC2(const char * pChar_src,
                          size_t unint_src_len,
                          unsigned short * pUnshort_dst,
                          size_t unint_dst_len);
  size_t convertUTF8ToUSC2(const char * pChar_src,
                           size_t unint_src_len,
                           unsigned short *pUnshort_dst,
                           size_t unint_dst_len);
  const unsigned short *convertWcharToUSC2(const wchar_t * pWchar_str,size_t unint_len);
  const wchar_t *convertUSC2ToWchar(const unsigned short * pUnshort_str,size_t unint_len);

  char *convertGBKToUTF8(const char * pchar_gbk, size_t unint_gbk_len, size_t * pUnint_utf8_len);
  char *convertUTF8ToGBK(const char * pChar_utf8, size_t unint_utf8_len, size_t * pUnint_gbk_len);

  char *convert(const char * pChar_in,
                size_t unint_inlen,
                size_t * pUnint_outlen,
                EnumCharset EnumCharset_from,
                EnumCharset EnumCharset_to);

private:
  std::vector< unsigned short > m_vecUnshort_buffer;
  std::vector< char > m_vecChar_buffer;
  std::vector< wchar_t > m_vecWchar_buffer;
};



#endif /* TRANSCODE_H_ */

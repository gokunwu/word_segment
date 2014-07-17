/*
 * SegmentContext.h
 *
 *  Created on: 2014年7月8日
 *      Author: kunwu
 */

#ifndef SEGMENTCONTEXT_H_
#define SEGMENTCONTEXT_H_

//#include <time.h>
#include "Common.h"

#pragma pack(push,4)
typedef struct SegmentToken
{
  unsigned int m_unint_offset;
  unsigned int m_unint_len;
  unsigned int m_unint_pos;
};

typedef struct SegmentContext
{
  //配置信息
  char m_char_with_small_term;                            //小粒度
  char m_char_with_pos;                                   //词性标注(TODO:标志的不准确)
  char m_char_with_norm;                                  //统一转换为半角小写
  char m_char_with_symbol;                                //保留符号

  char m_char_with_text;                                  //将分词结果输出到dstCharset。带词性时：中国/nx 北京/nx;不带词性时：中国 北京
  char m_char_with_token;                                 //保存SegmentToken信息,即词在原字符串中的offset、pos等
  char m_char_with_tradition;                             //繁体转换为简体,TODO:保留
  char m_char_release_memory;                             //线程安全的内存释放

  char m_char_with_html_parse;                            //需要html解析
  char m_char_output_word_separator;                      //单词间隔，默认是空格
  char m_char_output_pos_separator;                       //词性间隔，默认是"/"

  EnumGranularity m_EnumGranularity_granularity;        //切分粒度TODO:remove bWithSmallTerm

  //标准输入信息
  unsigned short *m_pUnshort_input_unicode;                  //输入 unicode，src + srcByte + srcCharset的结果
  unsigned short *m_pUnshort_normalized_input;               //对inputUni的归一化后(半角、小写)
  int m_int_input_num;                                    //normInput的个数，=  srcByte/2

  //输出token
  int m_int_token_num;                                    //token的个数
  SegmentToken *m_SegmentToken_token;                   //输出的SegmentToken信息


  //标准输出信息
  unsigned short *m_pUnshort_output_unicode; //分词结果,将通过dstCharset生成：dst 、dstByte
  int m_int_output_num;                  //outputUni的个数，= dstByte/2
  EnumCharset m_EnumCharset_dst_charset;
  void * m_pVoid_dst;
  int m_int_dst_byte;

  void * m_pVoid_handle;                   //保留(内部用，做内存管理)
};
#pragma pack()

#endif /* SEGMENTCONTEXT_H_ */

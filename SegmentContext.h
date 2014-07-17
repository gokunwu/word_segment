/*
 * SegmentContext.h
 *
 *  Created on: 2014��7��8��
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
  //������Ϣ
  char m_char_with_small_term;                            //С����
  char m_char_with_pos;                                   //���Ա�ע(TODO:��־�Ĳ�׼ȷ)
  char m_char_with_norm;                                  //ͳһת��Ϊ���Сд
  char m_char_with_symbol;                                //��������

  char m_char_with_text;                                  //���ִʽ�������dstCharset��������ʱ���й�/nx ����/nx;��������ʱ���й� ����
  char m_char_with_token;                                 //����SegmentToken��Ϣ,������ԭ�ַ����е�offset��pos��
  char m_char_with_tradition;                             //����ת��Ϊ����,TODO:����
  char m_char_release_memory;                             //�̰߳�ȫ���ڴ��ͷ�

  char m_char_with_html_parse;                            //��Ҫhtml����
  char m_char_output_word_separator;                      //���ʼ����Ĭ���ǿո�
  char m_char_output_pos_separator;                       //���Լ����Ĭ����"/"

  EnumGranularity m_EnumGranularity_granularity;        //�з�����TODO:remove bWithSmallTerm

  //��׼������Ϣ
  unsigned short *m_pUnshort_input_unicode;                  //���� unicode��src + srcByte + srcCharset�Ľ��
  unsigned short *m_pUnshort_normalized_input;               //��inputUni�Ĺ�һ����(��ǡ�Сд)
  int m_int_input_num;                                    //normInput�ĸ�����=  srcByte/2

  //���token
  int m_int_token_num;                                    //token�ĸ���
  SegmentToken *m_SegmentToken_token;                   //�����SegmentToken��Ϣ


  //��׼�����Ϣ
  unsigned short *m_pUnshort_output_unicode; //�ִʽ��,��ͨ��dstCharset���ɣ�dst ��dstByte
  int m_int_output_num;                  //outputUni�ĸ�����= dstByte/2
  EnumCharset m_EnumCharset_dst_charset;
  void * m_pVoid_dst;
  int m_int_dst_byte;

  void * m_pVoid_handle;                   //����(�ڲ��ã����ڴ����)
};
#pragma pack()

#endif /* SEGMENTCONTEXT_H_ */

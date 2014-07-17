/*
 * Common.h
 *
 *  Created on: 2014年7月8日
 *      Author: kunwu
 */

#ifndef COMMON_H_
#define COMMON_H_

typedef enum
{
  ENUM_CHARSET_GBK = 1,
  ENUM_CHARSET_UTF8,
  ENUM_CHARSET_UCS2
} EnumCharset; //字符编码集

typedef enum
{
  GRANULARITY_BIG = 1,
  GRANULARITY_SMALL,
  GRANULARITY_BOTH
} EnumGranularity; //切分粒度




#endif /* COMMON_H_ */

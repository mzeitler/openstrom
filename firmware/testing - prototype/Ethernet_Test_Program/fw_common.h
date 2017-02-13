/* 
    FW COMMON FILE
*/


/* Definition for mono-inclusion*/
#ifndef INC_COMMON
#define INC_COMMON 1


#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <stdio.h>


/*___________________ Declaration of exported types ______________________*/

/* variables types definitions */
typedef signed char         schar;
typedef unsigned char       uchar;
typedef unsigned short      ushort;
typedef unsigned long       ulong;
typedef unsigned long long  ulonglong;
typedef signed char         int8;
typedef unsigned char       uint8;
typedef unsigned short      uint16;
typedef unsigned long       uint32;
typedef unsigned long long  uint64;
typedef unsigned char       boolean;




/*___________________ Declaration of exported constants __________________*/

/* boolean true and false constants */
#define B_TRUE                  ((boolean)0xAA)
#define B_FALSE                 ((boolean)~B_TRUE)

/* NULL values constants */
#define UC_NULL                 ((uint8)0x00)
#define SC_NULL                 ((sint8)0x00)
#define US_NULL                 ((uint16)0x0000)
#define SS_NULL                 ((sint16)0x0000)
#define UL_NULL                 ((uint32)0x00000000)
#define SL_NULL                 ((sint32)0x00000000)
#define ULL_NULL                ((uint64)0x0000000000000000)
#define SLL_NULL                ((sint64)0x0000000000000000)
#define F_NULL                  ((float)0)
#define KUC_NULL                ((uint8)0x00)
#define KUS_NULL                ((uint16)0x0000)
#define NULL_PTR                ((void*) 0)

/* MAX and MIN values constants */
#define SC_MAX_CHAR             ((sint8)0x7F)
#define SC_MIN_CHAR             ((sint8)0X80)
#define UC_MAX_UCHAR            ((uint8)0xFF)
#define UC_MIN_UCHAR            ((uint8)0x00)
#define SS_MAX_SHORT            ((sint16)0x7FFF)
#define SS_MIN_SHORT            ((sint16)0x8000)
#define US_MAX_USHORT           ((uint16)0xFFFF)
#define US_MIN_USHORT           ((uint16)0x0000)
#define SL_MAX_ULONG            ((sint32)0x7FFFFFFFF)
#define SL_MIN_ULONG            ((sint32)0x80000000)
#define UL_MAX_ULONG            ((uint32)0xFFFFFFFF)
#define UL_MIN_ULONG            ((uint32)0x00000000)
#define US_MAX_10_BIT_VALUE     ((uint16)1023)

/* bit masks */
#define UC_CLEAR_LOW_NIBBLE_MSK     ((uint8)0xF0)
#define UC_CLEAR_HIGH_NIBBLE_MSK    ((uint8)0x0F)
#define US_CLEAR_HIGH_NIBBLE_MSK    ((uint8)0x0FFF)

/* unsigned 8-bit numerical constants */
#define UC_0                              ((uchar) 0x00)
#define UC_1                              ((uchar) (UC_0  + 1))
#define UC_2                              ((uchar) (UC_1  + 1))
#define UC_3                              ((uchar) (UC_2  + 1))
#define UC_4                              ((uchar) (UC_3  + 1))
#define UC_5                              ((uchar) (UC_4  + 1))
#define UC_6                              ((uchar) (UC_5  + 1))
#define UC_7                              ((uchar) (UC_6  + 1))
#define UC_8                              ((uchar) (UC_7  + 1))
#define UC_9                              ((uchar) (UC_8  + 1))
#define UC_10                             ((uchar) (UC_9  + 1))
#define UC_11                             ((uchar) (UC_10 + 1))
#define UC_12                             ((uchar) (UC_11 + 1))
#define UC_13                             ((uchar) (UC_12 + 1))
#define UC_14                             ((uchar) (UC_13 + 1))
#define UC_15                             ((uchar) (UC_14 + 1))
#define UC_16                             ((uchar) (UC_15 + 1))
#define UC_17                             ((uchar) (UC_16 + 1))
#define UC_18                             ((uchar) (UC_17 + 1))
#define UC_19                             ((uchar) (UC_18 + 1))
#define UC_20                             ((uchar) (UC_19 + 1))
#define UC_21                             ((uchar) (UC_20 + 1))
#define UC_22                             ((uchar) (UC_21 + 1))
#define UC_23                             ((uchar) (UC_22 + 1))
#define UC_24                             ((uchar) (UC_23 + 1))
#define UC_25                             ((uchar) (UC_24 + 1))
#define UC_26                             ((uchar) (UC_25 + 1))
#define UC_27                             ((uchar) (UC_26 + 1))
#define UC_28                             ((uchar) (UC_27 + 1))
#define UC_29                             ((uchar) (UC_28 + 1))
#define UC_30                             ((uchar) (UC_29 + 1))
#define UC_31                             ((uchar) (UC_30 + 1))
#define UC_32                             ((uchar) (UC_31 + 1))
#define UC_33                             ((uchar) (UC_32 + 1))
#define UC_34                             ((uchar) (UC_33 + 1))
#define UC_35                             ((uchar) (UC_34 + 1))
#define UC_36                             ((uchar) (UC_35 + 1))
#define UC_37                             ((uchar) (UC_36 + 1))
#define UC_38                             ((uchar) (UC_37 + 1))
#define UC_39                             ((uchar) (UC_38 + 1))
#define UC_40                             ((uchar) (UC_39 + 1))
#define UC_41                             ((uchar) (UC_40 + 1))
#define UC_42                             ((uchar) (UC_41 + 1))
#define UC_43                             ((uchar) (UC_42 + 1))
#define UC_44                             ((uchar) (UC_43 + 1))
#define UC_45                             ((uchar) (UC_44 + 1))
#define UC_46                             ((uchar) (UC_45 + 1))
#define UC_47                             ((uchar) (UC_46 + 1))
#define UC_48                             ((uchar) (UC_47 + 1))
#define UC_49                             ((uchar) (UC_48 + 1))
#define UC_50                             ((uchar) (UC_49 + 1))
#define UC_51                             ((uchar) (UC_50 + 1))
#define UC_52                             ((uchar) (UC_51 + 1))
#define UC_53                             ((uchar) (UC_52 + 1))
#define UC_54                             ((uchar) (UC_53 + 1))
#define UC_55                             ((uchar) (UC_54 + 1))
#define UC_56                             ((uchar) (UC_55 + 1))
#define UC_57                             ((uchar) (UC_56 + 1))
#define UC_58                             ((uchar) (UC_57 + 1))
#define UC_59                             ((uchar) (UC_58 + 1))
#define UC_60                             ((uchar) (UC_59 + 1))
#define UC_61                             ((uchar) (UC_60 + 1))
#define UC_62                             ((uchar) (UC_61 + 1))
#define UC_63                             ((uchar) (UC_62 + 1))
#define UC_64                             ((uchar) (UC_63 + 1))
#define UC_65                             ((uchar) (UC_64 + 1))
#define UC_66                             ((uchar) (UC_65 + 1))
#define UC_67                             ((uchar) (UC_66 + 1))
#define UC_68                             ((uchar) (UC_67 + 1))
#define UC_69                             ((uchar) (UC_68 + 1))
#define UC_70                             ((uchar) (UC_69 + 1))
#define UC_71                             ((uchar) (UC_70 + 1))
#define UC_72                             ((uchar) (UC_71 + 1))
#define UC_73                             ((uchar) (UC_72 + 1))
#define UC_74                             ((uchar) (UC_73 + 1))
#define UC_75                             ((uchar) (UC_74 + 1))
#define UC_76                             ((uchar) (UC_75 + 1))
#define UC_77                             ((uchar) (UC_76 + 1))
#define UC_78                             ((uchar) (UC_77 + 1))
#define UC_79                             ((uchar) (UC_78 + 1))
#define UC_80                             ((uchar) (UC_79 + 1))
#define UC_81                             ((uchar) (UC_80 + 1))
#define UC_82                             ((uchar) (UC_81 + 1))
#define UC_83                             ((uchar) (UC_82 + 1))
#define UC_84                             ((uchar) (UC_83 + 1))
#define UC_85                             ((uchar) (UC_84 + 1))
#define UC_86                             ((uchar) (UC_85 + 1))
#define UC_87                             ((uchar) (UC_86 + 1))
#define UC_88                             ((uchar) (UC_87 + 1))
#define UC_89                             ((uchar) (UC_88 + 1))
#define UC_90                             ((uchar) (UC_89 + 1))
#define UC_91                             ((uchar) (UC_90 + 1))
#define UC_92                             ((uchar) (UC_91 + 1))
#define UC_93                             ((uchar) (UC_92 + 1))
#define UC_94                             ((uchar) (UC_93 + 1))
#define UC_95                             ((uchar) (UC_94 + 1))
#define UC_96                             ((uchar) (UC_95 + 1))
#define UC_97                             ((uchar) (UC_96 + 1))
#define UC_98                             ((uchar) (UC_97 + 1))
#define UC_99                             ((uchar) (UC_98 + 1))
#define UC_100                            ((uchar) (UC_99 + 1))
#define UC_125                            ((uchar) (UC_100 + 25))
#define UC_127                            ((uchar) (UC_100 + 27))
#define UC_128                            ((uchar) (UC_100 + 28))
#define UC_129                            ((uchar) (UC_100 + 29))
#define UC_200                            ((uchar) (UC_100 + 100))
#define UC_253                            ((uchar) (UC_100 + 153))
#define UC_254                            ((uchar) (UC_253 + 1))
#define UC_255                            ((uchar) (UC_254 + 1))

/* unsigned 16-bit numerical constants */
#define US_1                              ((ushort)   1)
#define US_2                              ((ushort)   2)
#define US_3                              ((ushort)   3)
#define US_4                              ((ushort)   4)
#define US_5                              ((ushort)   5)
#define US_6                              ((ushort)   6)
#define US_7                              ((ushort)   7)
#define US_8                              ((ushort)   8)
#define US_9                              ((ushort)   9)
#define US_10                             ((ushort)  10)
#define US_11                             ((ushort)  11)
#define US_12                             ((ushort) 12)
#define US_13                             ((ushort)  13)
#define US_14                             ((ushort) 14)
#define US_15                             ((ushort)  15)
#define US_16                             ((ushort) 16)
#define US_17                             ((ushort)  17)
#define US_18                             ((ushort) 18)
#define US_19                             ((ushort)  19)
#define US_20                             ((ushort)  20)
#define US_21                             ((ushort)  21)
#define US_22                             ((ushort)  22)
#define US_23                             ((ushort) 23)
#define US_24                             ((ushort) 24)
#define US_25                             ((ushort)  25)
#define US_26                             ((ushort) 26)
#define US_27                             ((ushort) 27)
#define US_28                             ((ushort) 28)
#define US_29                             ((ushort) 29)
#define US_30                             ((ushort)  30)
#define US_31                             ((ushort)  31)
#define US_32                             ((ushort) 32)
#define US_33                             ((ushort)  33)
#define US_34                             ((ushort)  34)
#define US_35                             ((ushort)  35)
#define US_36                             ((ushort) 36)
#define US_37                             ((ushort) 37)
#define US_38                             ((ushort) 38)
#define US_39                             ((ushort) 39)
#define US_40                             ((ushort)  40)
#define US_41                             ((ushort) 41)
#define US_42                             ((ushort) 42)
#define US_43                             ((ushort) 43)
#define US_44                             ((ushort)  44)
#define US_45                             ((ushort)  45)
#define US_46                             ((ushort) 46)
#define US_47                             ((ushort) 47)
#define US_48                             ((ushort) 48)
#define US_49                             ((ushort) 49)
#define US_50                             ((ushort)  50)
#define US_51                             ((ushort) 51)
#define US_52                             ((ushort) 52)
#define US_53                             ((ushort) 53)
#define US_54                             ((ushort) 54)
#define US_55                             ((ushort)  55)
#define US_56                             ((ushort) 56)
#define US_57                             ((ushort) 57)
#define US_58                             ((ushort) 58)
#define US_59                             ((ushort)  59)
#define US_60                             ((ushort)  60)
#define US_61                             ((ushort) 61)
#define US_62                             ((ushort) 62)
#define US_63                             ((ushort) 63)
#define US_64                             ((ushort) 64)
#define US_65                             ((ushort)  65)
#define US_66                             ((ushort)  66)
#define US_67                             ((ushort) 67)
#define US_68                             ((ushort) 68)
#define US_69                             ((ushort) 69)
#define US_70                             ((ushort)  70)
#define US_71                             ((ushort) 71)
#define US_72                             ((ushort) 72)
#define US_73                             ((ushort) 73)
#define US_74                             ((ushort) 74)
#define US_75                             ((ushort)  75)
#define US_76                             ((ushort) 76)
#define US_77                             ((ushort)  77)
#define US_78                             ((ushort) 78)
#define US_79                             ((ushort) 79)
#define US_80                             ((ushort)  80)
#define US_81                             ((ushort) 81)
#define US_82                             ((ushort) 82)
#define US_83                             ((ushort) 83)
#define US_84                             ((ushort) 84)
#define US_85                             ((ushort)  85)
#define US_86                             ((ushort) 86)
#define US_87                             ((ushort) 87)
#define US_88                             ((ushort)  88)
#define US_89                             ((ushort) 89)
#define US_90                             ((ushort)  90)
#define US_91                             ((ushort) 91)
#define US_92                             ((ushort) 92)
#define US_93                             ((ushort) 93)
#define US_94                             ((ushort) 94)
#define US_95                             ((ushort) 95)
#define US_96                             ((ushort) 96)
#define US_97                             ((ushort) 97)
#define US_98                             ((ushort) 98)
#define US_99                             ((ushort) 99)
#define US_100                            ((ushort) 100)
#define US_125                            ((ushort) 125)
#define US_102                            ((ushort) 102)
#define US_120                            ((ushort) 120)
#define US_125                            ((ushort) 125)
#define US_140                            ((ushort) 140)
#define US_173                            ((ushort) 173)
#define US_200                            ((ushort) 200)
#define US_223                            ((ushort) 223)
#define US_255                            ((ushort) 255)
#define US_256                            ((ushort) 256)
#define US_273                            ((ushort) 273)
#define US_299                            ((ushort) 299)
#define US_300                            ((ushort) 300)
#define US_307                            ((ushort) 307)
#define US_400                            ((ushort) 400)
#define US_420                            ((ushort) 420)
#define US_440                            ((ushort) 440)
#define US_450                            ((ushort) 450)
#define US_490                            ((ushort) 490)
#define US_500                            ((ushort) 500)
#define US_512                            ((ushort) 512)
#define US_520                            ((ushort) 520)
#define US_530                            ((ushort) 530)
#define US_550                            ((ushort) 550)
#define US_590                            ((ushort) 590)
#define US_600                            ((ushort) 600)
#define US_620                            ((ushort) 620)
#define US_660                            ((ushort) 660)
#define US_716                            ((ushort) 716)
#define US_730                            ((ushort) 730)
#define US_765                            ((ushort) 765)
#define US_800                            ((ushort) 800)
#define US_900                            ((ushort) 900)
#define US_1000                           ((ushort) 1000)
#define US_1003                           ((ushort) 1003)
#define US_1023                           ((ushort) 1023)
#define US_1100                           ((ushort) 1100)
#define US_1200                           ((ushort) 1200)
#define US_1300                           ((ushort) 1300)
#define US_1400                           ((ushort) 1400)
#define US_1500                           ((ushort) 1500)
#define US_1600                           ((ushort) 1600)
#define US_1700                           ((ushort) 1700)
#define US_1800                           ((ushort) 1800)
#define US_2000                           ((ushort) 2000)
#define US_2200                           ((ushort) 2200)
#define US_2500                           ((ushort) 2500)
#define US_3000                           ((ushort) 3000)
#define US_5000                           ((ushort) 5000)
#define US_5200                           ((ushort) 5200)
#define US_7000                           ((ushort) 7000)
#define US_8000                           ((ushort) 8000)
#define US_8600                           ((ushort) 8600)
#define US_10000                          ((ushort) 10000)
#define US_25000                          ((ushort) 25000)
#define US_50000                          ((ushort) 50000)

/* signed 8-bit numerical constants */
#define SC_18                               ((schar)   18)

/* unsigned 32-bit numerical constants */
#define UL_1                              ((ulong)      1)
#define UL_2                              ((ulong)      2)
#define UL_10                             ((ulong)     10)
#define UL_16                             ((ulong)     16)
#define UL_40                             ((ulong)     40)
#define UL_50                             ((ulong)     50)
#define UL_60                             ((ulong)     60)
#define UL_1000                           ((ulong)   1000)
#define UL_12500                          ((ulong)  12500)
#define UL_32000                          ((ulong)  32000)
#define UL_100000                         ((ulong) 100000)
#define UL_1000000                        ((ulong)1000000)

/* signed 32-bit numerical constants */
#define L_1000000                         ((long) 1000000)

/* bit positions definitions */
#define UC_BIT0             ((uchar)0x1)
#define UC_BIT1             ((uchar)0x2)
#define UC_BIT2             ((uchar)0x4)
#define UC_BIT3             ((uchar)0x8)
#define UC_BIT4             ((uchar)0x10)
#define UC_BIT5             ((uchar)0x20)

/* unsigned 8-bit shift masks definitions */
#define UC_SHIFT_1            ((uchar)0x01)
#define UC_SHIFT_2            ((uchar)0x02)
#define UC_SHIFT_3            ((uchar)0x03)
#define UC_SHIFT_4            ((uchar)0x04)
#define UC_SHIFT_5            ((uchar)0x05)
#define UC_SHIFT_6            ((uchar)0x06)

/* unsigned 16-bit shift masks definitions */
#define US_SHIFT_1            ((ushort)0x0001)
#define US_SHIFT_2            ((ushort)0x0002)
#define US_SHIFT_3            ((ushort)0x0003)
#define US_SHIFT_4            ((ushort)0x0004)
#define US_SHIFT_5            ((ushort)0x0005)
#define US_SHIFT_6            ((ushort)0x0006)
#define US_SHIFT_7            ((ushort)0x0007)
#define US_SHIFT_8            ((ushort)0x0008)
#define US_SHIFT_16           ((ushort)0x0010)

/* unsigned 32-bit shift masks definitions */
#define UL_SHIFT_0            ((ulong)0x00000000)
#define UL_SHIFT_1            ((ulong)0x00000001)
#define UL_SHIFT_2            ((ulong)0x00000002)
#define UL_SHIFT_3            ((ulong)0x00000003)
#define UL_SHIFT_4            ((ulong)0x00000004)
#define UL_SHIFT_5            ((ulong)0x00000005)
#define UL_SHIFT_6            ((ulong)0x00000006)
#define UL_SHIFT_7            ((ulong)0x00000007)
#define UL_SHIFT_8            ((ulong)0x00000008)
#define UL_SHIFT_9            ((ulong)0x00000009)
#define UL_SHIFT_10           ((ulong)10)
#define UL_SHIFT_11           ((ulong)11)
#define UL_SHIFT_12           ((ulong)12)
#define UL_SHIFT_13           ((ulong)13)
#define UL_SHIFT_14           ((ulong)14)
#define UL_SHIFT_15           ((ulong)15)
#define UL_SHIFT_16           ((ulong)0x00000010)
#define UL_SHIFT_17           ((ulong)17)
#define UL_SHIFT_18           ((ulong)18)
#define UL_SHIFT_19           ((ulong)19)
#define UL_SHIFT_20           ((ulong)20)
#define UL_SHIFT_21           ((ulong)21)
#define UL_SHIFT_22           ((ulong)22)
#define UL_SHIFT_23           ((ulong)23)
#define UL_SHIFT_24           ((ulong)0x00000018)
#define UL_SHIFT_25           ((ulong)25)
#define UL_SHIFT_28           ((ulong)28)

/* unsigned 64-bit shift masks definitions */
#define ULL_SHIFT_8             ((ulonglong)0x0000000000000008)
#define ULL_SHIFT_16            ((ulonglong)0x0000000000000010)
#define ULL_SHIFT_24            ((ulonglong)0x0000000000000018)
#define ULL_SHIFT_32            ((ulonglong)0x0000000000000020)
#define ULL_SHIFT_40            ((ulonglong)0x0000000000000028)
#define ULL_SHIFT_64            ((ulonglong)0x0000000000000040)




/*_____________________ Exported macros definition ____________________*/

/* types */
#define EXPORTED
#define EXTERN      extern
#define VOLATILE    volatile
#define LOCAL       static

/* perform a 32-bit alignment of a 8-bit pointer */
#define ALIGN_32BIT_OF_8BIT_PTR(x)          ((x) = (uint8 *)((uint8 *)(x) - (uint8)(((uint32)(x) & 0xFFFF) % UC_4)))

/* perform a 32-bit alignment of a 32-bit pointer */
#define ALIGN_32BIT_OF_32BIT_PTR(x)         ((x) = (uint32 *)((uint8 *)(x) - (uint8)(((uint32)(x) & 0xFFFF) % UC_4)))

/* swap bytes - store in big endian order */
#define SWAP_BYTES_ORDER_16BIT_(x)          ((((x) & 0xFF00) >> US_SHIFT_8) | (((x) & 0x00FF) << US_SHIFT_8))
#define SWAP_BYTES_ORDER_32BIT_(x)          ((((x) & 0xFF000000) >> UL_SHIFT_24) | (((x) & 0x00FF0000) >> UL_SHIFT_8) | (((x) & 0x0000FF00) << UL_SHIFT_8) | (((x) & 0x000000FF) << UL_SHIFT_24))

/* write in big endian order a 32-bits word, increment pointer and clear the word */
#define WRITE_32BIT_AND_NEXT(x,y)           (*(x) = ((((y) & 0xFF000000) >> UL_SHIFT_24) | (((y) & 0x00FF0000) >> UL_SHIFT_8) | (((y) & 0x0000FF00) << UL_SHIFT_8) | (((y) & 0x000000FF) << UL_SHIFT_24))); \
                                            ((y) = 0);  \
                                            ((x)++)

/* read in big endian order a 32-bits word, increment pointer and clear the word first */
#define READ_32BIT_AND_NEXT(x,y)            ((y) = 0);  \
                                            ((y) = ((((*(x)) & 0xFF000000) >> UL_SHIFT_24) | (((*(x)) & 0x00FF0000) >> UL_SHIFT_8) | (((*(x)) & 0x0000FF00) << UL_SHIFT_8) | (((*(x)) & 0x000000FF) << UL_SHIFT_24)));  \
                                            ((x)++)

/* write a single byte */
#define WRITE_8BIT_AND_NEXT(x,y)            (*((uint8 *)(x)) = y);  \
                                            ((x) = (uint32 *)((uint8 *)(x) + UC_1))

/* Write N bytes from a given pointer */
#define WRITE_N_BYTES(x, y, z)              while((z) > 0)                              \
                                            {                                           \
                                                *((uint8 *)(x)) = (y);                  \
                                                (x) = (uint32 *)((uint8 *)(x) + UC_1);  \
                                                (z)--;                                  \
                                            }

/* Read a 32-bit word */
#define READ_SWAP_4_BYTES(x,y)              (y = 0);                                    \
                                            (y = (*(x)++) << UL_SHIFT_24);              \
                                            (y |= (*(x)++) << UL_SHIFT_16);             \
                                            (y |= (*(x)++) << UL_SHIFT_8);              \
                                            (y |= *(x)++)

/* Write a 32-bit word */
#define WRITE_SWAP_4_BYTES(x,y)             (*(x) = (uint8)(((y) & 0xFF000000) >> UL_SHIFT_24));        \
                                            (*((x) + 1) = (uint8)(((y) & 0x00FF0000) >> UL_SHIFT_16));  \
                                            (*((x) + 2) = (uint8)(((y) & 0x0000FF00) >> UL_SHIFT_8));   \
                                            (*((x) + 3) = (uint8)((y) & 0x000000FF));

/* write in big endian order a 16-bits word */
#define WRITE_16BIT(x,y)                    (*(x) = ((((y) & 0xFF00) >> UL_SHIFT_8) | (((y) & 0x00FF) << UL_SHIFT_8)))

/* read in big endian order a 16-bits word */
#define READ_16BIT(x,y)                     ((y) = 0);  \
                                            ((y) = ((((*(x)) & 0xFF00) >> UL_SHIFT_8) | (((*(x)) & 0x00FF) << UL_SHIFT_8)))

/* write in big endian order a 32-bits word */
#define WRITE_32BIT(x,y)                    (*(x) = ((((y) & 0xFF000000) >> UL_SHIFT_24) | (((y) & 0x00FF0000) >> UL_SHIFT_8) | (((y) & 0x0000FF00) << UL_SHIFT_8) | (((y) & 0x000000FF) << UL_SHIFT_24))); \
                                            ((y) = 0)

/* read in big endian order a 32-bits word */
#define READ_32BIT(x,y)                     ((y) = 0);  \
                                            ((y) = ((((*(x)) & 0xFF000000) >> UL_SHIFT_24) | (((*(x)) & 0x00FF0000) >> UL_SHIFT_8) | (((*(x)) & 0x0000FF00) << UL_SHIFT_8) | (((*(x)) & 0x000000FF) << UL_SHIFT_24)))




/* Malloc, memory and strings macros */
#define MEM_MALLOC(x)                       (malloc((x)))
#define MEM_FREE(x)                         (free((x)))
#define MEM_COPY(x,y,z)                     (memcpy((x),(y),(z)))
#define MEM_COMPARE(x,y,z)                  (strncmp((x),(y),(z)))
#define MEM_GET_LENGTH(x)                   (strlen(x))




/*_____________________ Common inclusions ____________________*/

#include "fw_config.h"




#endif /* end of conditional inclusion of common.h */


/* END OF FILE */

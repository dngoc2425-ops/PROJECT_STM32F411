#ifndef _NVIC_H_
#define _NVIC_H_
// declaration registers
#define NVIC_ISER_BASEADDRESS 0xE000E100UL
#define NVIC_ICER_BASEADDRESS 0XE000E180UL
#define NVIC_ISPR_BASEADDRESS 0XE000E200UL
#define NVIC_ICPR_BASEADDRESS 0XE000E280UL
#define NVIC_IABR_BASEADDRESS 0xE000E300UL
#define NVIC_IPR_BASEADDRESS  0xE000E400UL
// define pointer of registers
#define NVIC_ISER ((volatile unsigned long * ) NVIC_ISER_BASEADDRESS)
#define NVIC_ICER ((volatile unsigned long * ) NVIC_ICER_BASEADDRESS)
#define NVIC_ISPR ((volatile unsigned long * ) NVIC_ISPR_BASEADDRESS)
#define NVIC_ICPR ((volatile unsigned long * ) NVIC_ICPR_BASEADDRESS)
#define NVIC_IABR ((volatile unsigned long * ) NVIC_IABR_BASEADDRESS)
#define NVIC_IPR  ((volatile unsigned long * ) NVIC_IPR_BASEADDRESS)
// define macro function 
void Enable_NVIC  (unsigned char position);
void Disable_NVIC (unsigned char position);
void Set_Pending  (unsigned char position);
void Clear_Pending(unsigned char position);
void Set_Priority (unsigned char position , unsigned char priority );
#endif
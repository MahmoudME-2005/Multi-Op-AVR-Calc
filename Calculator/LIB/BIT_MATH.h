/*
 * BIT_MATH.h
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(reg,pin) reg |=(1<<pin)
#define CLR_BIT(reg,pin) reg &=(~(1<<pin))
#define GET_BIT(reg,pin) (reg>>pin)&1




#endif /* BIT_MATH_H_ */
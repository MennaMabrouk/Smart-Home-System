/*
 * ADC_config.h
 *
 *  Created on: Aug 24, 2023
 *      Author: PC
 */

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

#define ADMUX_REFS1      7
#define ADMUX_REFS0      6
#define ADMUX_ADLAR      5

#define ADCSRA_ADEN      7
#define ADCSRA_ADSC      6
#define ADCSRA_ADTE      5
#define ADCSRA_ADIF      4
#define ADCSRA_ADIE      3
#define ADCSRA_ADPS2     2
#define ADCSRA_ADPS1     1
#define ADCSRA_ADPS0     0

#define chanel0          0b00000
#define chanel1          0b00001
#define chanel2          0b00010
#define chanel3          0b00011
#define chanel4          0b00100
#define chanel5          0b00101
#define chanel6          0b00110
#define chanel7          0b00111

#define PRE_SCALER_VALUE 128

#endif /* ADC_CONFIG_H_ */

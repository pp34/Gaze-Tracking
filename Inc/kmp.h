#ifndef __kmp_H
#define __kmp_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"
#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "connect.h"
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

int str_kmp(const uint8_t A[], const uint8_t a[]);
	 
int pp_match(const uint8_t A[], const uint8_t a[]);	 
void cmd_match(const uint8_t A[]);
int pp_strlen(const uint8_t *str);
int pp_numlen(const uint8_t num[]);
uint8_t *pp_numcat(const uint8_t front[], const uint8_t behind[]);
/* USER CODE BEGIN Prototypes */

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ pinoutConfig_H */

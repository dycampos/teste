/*
 * lcd.h
 *
 *  Created on: Aug 20, 2018
 *      Author: Renan Augusto Starke
 *
 *      Adaptado de AVR e Arduino: T?cnicas de Projeto, 2a ed. - 2012.
 *      Instituto Federal de Santa Catarina
 */

#ifndef _LCD_H
#define _LCD_H

#ifndef F_CPU
	#define F_CPU 16000000UL
#endif

#include <util/delay.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdio.h>

#include "bits.h"
#include "avr_gpio.h"


//Defini??es para facilitar a troca dos pinos do hardware e facilitar a re-programa??o

#define NIBBLE_DADOS	1		//0 para via de dados do LCD nos 4 LSBs do PORT empregado (Px0-D4, Px1-D5, Px2-D6, Px3-D7)
								//1 para via de dados do LCD nos 4 MSBs do PORT empregado (Px4-D4, Px5-D5, Px6-D6, Px7-D7)
#define DADOS_LCD	GPIO_D

#define CONTR_LCD		GPIO_B
#define E    			PB1     //pino de habilita??o do LCD (enable)
#define RS   			PB0     //pino para informar se o dado ? uma instru??o ou caractere

/**
  * @brief  Configura hardware.
  * @param	Nenhum
  *
  * @retval Nenhum.
  */
void inic_LCD_4bits();

/**
  * @brief  Retorna o stream interno para utilizar a libc (printf no LCD)
  * @param	Nenhum
  *
  * @retval FILE: ponteiro do stream para utiliza com fprintf.
  */
FILE * inic_stream();

/**
  * @brief  Envia um dado est?tico para o display: caractere ou comando.
  * @param c: valor do comando.
  * @param cd: 0 para comando. 1 para caractere.
  *
  * @retval Nenhum
  */
void cmd_LCD(uint8_t c, uint8_t cd);

/**
  * @brief  Escreve um string est?tica (sem printf) no LCD.
  * @param c: ponteiro para a string em RAM
  *
  * @retval Nenhum
  */
void escreve_LCD(char *c);

/**
  * @brief  Escreve um string est?tica (sem printf) no LCD.
  * @param c: ponteiro para a string em FLASH
  *
  * @retval Nenhum
  */
void escreve_LCD_Flash(const char *c);

/**
  * @brief Escreve um caractere no stream. Fun??o utilizada pela libc.
  * @param c: caractere a ser escrito.
  * @param fp: ponteiro do stream inicilizado que receber? o dado.
  *
  * @retval int maior que zero se sucesso.
  */
int lcd_putchar(char c, FILE *fp);


#endif

/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <stats.h> 
 * @brief <Header file for stats.c>
 *
 * <Contains function declarations for all the funstions in stats.c>
 *
 * @author <Srilatha Bandaru>
 * @date <14th Apr 2018 >
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief <Minimum Number>
 *
 * <This function finds the minimum number in a given size of a list>
 *
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 *
 * @return <Add Return Informaiton here>
 */

unsigned char find_minimum(unsigned char *, unsigned int );
unsigned char find_maximum(unsigned char *, unsigned int );
unsigned char find_mean(unsigned char *, unsigned int );
unsigned char find_median(unsigned char *, unsigned int );
unsigned char sort_array(unsigned char *, unsigned int );
unsigned char print_array(unsigned char *, unsigned int );
unsigned char print_statistics(unsigned char *, unsigned int );

/**
 * @brief <Minimum Number>
 *
 * <This function finds the minimum number in a given size of a list>
 *
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 *
 * @return <Add Return Informaiton here>
 */

#endif /* __STATS_H__ */

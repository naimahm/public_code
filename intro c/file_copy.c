/*
 *  file_copy.c
 *  program is a binary file copier, of all file types
 *
 *  Created by Naimah Mumin on 9/29/13.
 *  Copyright 2013 Naimerica. All rights reserved.
 *
 */


#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#define NAME "Naimah Mumin"

int main()
{
	char source[100], destination[100];
	char buffer[23];
	struct stat *buf;
	void *readbuf;
	int source_fd, destination_fd, readbytes, totalbytes = 0;
	printf("Welcome to File Copy by %s!\n", NAME);
	
	//get name of input file
	printf("Enter the name of the source file: \n");
	scanf("%s",source);
	
	
	//if file doesn't exst abort
 	if(access(source, F_OK) == -1){
		printf("Problem with file: %s\n", strerror(errno));
		return 0;
	}
	
	//get name of destination file
	printf("Enter the name of the destination file: \n");
	scanf("%s",destination);
	
	
	source_fd = open(source,O_RDONLY);
	
	//if file exists abort
	if(access(destination, F_OK) == 0){
		printf("Problem with file: %s\n", strerror(errno));
		return 0;
	}
	
	destination_fd = open(destination, O_WRONLY | O_CREAT, S_IRWXG | S_IRWXU | S_IRWXO);
	if(destination_fd == -1){
		printf("Problem with file: %s\n", strerror(errno));
		return 0;
	}
	
	while (readbytes = read(source_fd,buffer ,23)){
		totalbytes += readbytes;
		write(destination_fd, buffer, readbytes);
		printf("buffer: %s\n", buffer);
	}
	
	//close destination file
	close(destination_fd);
	
	//return message]n
	printf("File Copy was successful, with %d bytes copied.", totalbytes);
	
	
	return 0;	
}
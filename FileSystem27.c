


// 15/07/2023

// show empty files


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#inclue<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>



int main(int argc,char *argv[])
{
	char DirName[20];
	DIR *dp=NULL;
	
	struct dirent *entry=NULL;
	char name[30];
	struct stat sobj;
	
	printf"Enter name of directory : \n");
	scanf("%s",DirName);
	
	dp=opendir(DirName);
	
	if(dp==NULL)
	{
		printf("Unable to open directory\n");
		
		return -1;
		
	}
	
	while((entry=readdir(dp))!=NULL)
	{
		
		sprintf(name,"%s/%s",DirName,entry->d_name);
		stat(name,&sobj);
		
		if(S_ISREG(sobj.st_mode))
		{
			if(sobj.st_size==0)
			{
				printf("%s is an empty file : \n",name);
			}
			
		}
		
		
		
	}
	
	printf("Name of largest file : %s with size %d bytes \n",namecopy,iMax);
	
	
	closedir(dp);
	
	return 0;
	
}


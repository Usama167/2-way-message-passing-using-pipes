#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	int first,second;
	printf("Enter processes for communication: ");
	scanf("%d %d",&first,&second);
	if((first==1 && second==2)||(first==2 && second==1)){
		const char *cmd = "gnome-terminal --command=\"./1,2.sh\" ";
		system(cmd);
		const char *smd= "gnome-terminal --command=\"./2,1.sh\" ";
		system(smd);
	} 
	else if((first==1 && second==3)||(first==3 && second==1)){
		const char *cmd = "gnome-terminal --command=\"./1,3.sh\" ";
		system(cmd);
		const char *smd= "gnome-terminal --command=\"./3,1.sh\" ";
		system(smd);
	}
	
	else if((first==1 && second==4)||(first==4 && second==1)){
		const char *cmd = "gnome-terminal --command=\"./1,4.sh\" ";
		system(cmd);
		const char *smd= "gnome-terminal --command=\"./4,1.sh\" ";
		system(smd);
	}
	
	else if((first==2 && second==3)||(first==3 && second==2)){
		const char *cmd = "gnome-terminal --command=\"./2,3.sh\" ";
		system(cmd);
		const char *smd= "gnome-terminal --command=\"./3,2.sh\" ";
		system(smd);
	}
	
	else if((first==2 && second==4)||(first==4 && second==2)){
		const char *cmd = "gnome-terminal --command=\"./2,4.sh\" ";
		system(cmd);
		const char *smd= "gnome-terminal --command=\"./4,2.sh\" ";
		system(smd);
	}
	
	
	else if((first==3 && second==4)||(first==4 && second==3)){
		const char *cmd = "gnome-terminal --command=\"./3,4.sh\" ";
		system(cmd);
		const char *smd= "gnome-terminal --command=\"./4,3.sh\" ";
		system(smd);
	}
	
}

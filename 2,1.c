//write first then read
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
 
int main()
{
    int fd;
 
    // FIFO file path
    char * myfifo = "/tmp/myfifo";
 
    // Creating the FIFO file
    mkfifo(myfifo, 0666);
    int login;
    printf("Enter User to write from: ");
    scanf("%d",&login);
    //clearing buffer 
    while ((getchar()) != '\n');
    char arr1[80], arr2[80];
    //checking condition which processor will write first
    if(login==1){
    while(1)
    {
	if((arr2[0]=='b' && arr2[1]=='y' && arr2[2]=='e')||(arr1[0]=='b' && arr1[1]=='y' && arr1[2]=='e')){
		return 0;
	}
        // Open FIFO for write only
        fd = open(myfifo, O_WRONLY);
 
        //user to write message
        fgets(arr2, 80, stdin);
 
        //write the message on FIFO file and close
        write(fd, arr2, strlen(arr2)+1);
        close(fd);
 
        // Open FIFO for Read only
        fd = open(myfifo, O_RDONLY);
 
        // Read from FIFO
        read(fd, arr1, sizeof(arr1));
 
        // Print the read message
        printf("User2: %s\n", arr1);
        close(fd);
    }
}
	else if(login==2){
	while(1){
	if((arr2[0]=='b' && arr2[1]=='y' && arr2[2]=='e')||(arr1[0]=='b' && arr1[1]=='y' && arr1[2]=='e')){
		return 0;
	}
	// Open FIFO for write only
        fd = open(myfifo,O_WRONLY);
	
	//user to write message
        fgets(arr2, 80, stdin);

	//write the message on FIFO file and close
        write(fd, arr2, strlen(arr2)+1);
        close(fd);
	
	 // Open FIFO for Read only
        fd = open(myfifo,O_RDONLY);
	
	// Read from FIFO
        read(fd, arr1, 80);
 
        // Print the read message
        printf("User1: %s\n", arr1);
        close(fd);
 }
}
    return 0;
}

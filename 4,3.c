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
    char * myfifo3 = "/tmp/myfifo3";
 
    // Creating the FIFO file
    mkfifo(myfifo3, 0666);
    int login;
    printf("Enter User to write from: ");
    scanf("%d",&login);
    //clearing buffer 
    while ((getchar()) != '\n');
    char arr1[80], arr2[80];
    if(login==3){
    while (1)
    {
	if((arr2[0]=='b' && arr2[1]=='y' && arr2[2]=='e')||(arr1[0]=='b' && arr1[1]=='y' && arr1[2]=='e')){
		return 0;
	}
        // Open FIFO for write only
        fd = open(myfifo3, O_WRONLY);
 
        //user to write message
        fgets(arr2, 80, stdin);
 
        //write the message on FIFO file and close
        write(fd, arr2, strlen(arr2)+1);
        close(fd);
 
        // Open FIFO for Read only
        fd = open(myfifo3, O_RDONLY);
 
        // Read from FIFO
        read(fd, arr1, sizeof(arr1));
 
        // Print the read message
        printf("User4: %s\n", arr1);
        close(fd);
    }
}
	else if(login==4){
	while(1){
	if((arr2[0]=='b' && arr2[1]=='y' && arr2[2]=='e')||(arr1[0]=='b' && arr1[1]=='y' && arr1[2]=='e')){
		return 0;
	}
        // Open FIFO for write only
        fd = open(myfifo3,O_WRONLY);
	
	//user to write message
        fgets(arr2, 80, stdin);
	
	//write the message on FIFO file and close
        write(fd, arr2, strlen(arr2)+1);
        close(fd);
	
	// Open FIFO for Read only
        fd = open(myfifo3,O_RDONLY);
	// Read from FIFO
        read(fd, arr1, 80);
 
        // Print the read message
        printf("User3: %s\n", arr1);
        close(fd);
 }
}
    return 0;
}

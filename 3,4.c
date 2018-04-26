//reads first then write
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
 
int main()
{
    int fd1;
 
    // FIFO file path
    char * myfifo3 = "/tmp/myfifo3";
 
    //creating the FIFO file
    mkfifo(myfifo3, 0666);
    int login;
    printf("Enter User to read from: ");
    scanf("%d",&login); 
    //clearing buffer
    while ((getchar()) != '\n');
 
    char str1[80], str2[80];
    if(login==3){
    
    while(1){
	if((str2[0]=='b' && str2[1]=='y' && str2[2]=='e')||(str1[0]=='b' && str1[1]=='y' && str1[2]=='e')) {
		return 0; }
        //Open FIFO for read only
        fd1 = open(myfifo3,O_RDONLY);
	//Read from FIFO
        read(fd1, str1, 80);
 
        // Print the read message
        printf("User3: %s\n", str1);
        close(fd1);
 
        //Open FIFO for Write only.
        fd1 = open(myfifo3,O_WRONLY);
        //user to write message
	fgets(str2, 80, stdin);
	//write the message on FIFO file and close
        write(fd1, str2, strlen(str2)+1);
        close(fd1);
    }
    
}
else if(login==4){

        
	while(1){
	if((str2[0]=='b' && str2[1]=='y' && str2[2]=='e')||(str1[0]=='b' && str1[1]=='y' && str1[2]=='e')) {
		return 0; }
        // Open FIFO for Read only
        fd1 = open(myfifo3, O_RDONLY);
 
        // Read from FIFO
        read(fd1, str1, sizeof(str1));
 
        // Print the read message
        printf("User4: %s\n", str1);
        close(fd1);

	// Open FIFO for write only
        fd1 = open(myfifo3, O_WRONLY);
 
        //user to write message
        fgets(str2, 80, stdin);
 
        //write the message on FIFO file and close
        write(fd1, str2, strlen(str2)+1);
        close(fd1);



}

}
 
    return 0;
}

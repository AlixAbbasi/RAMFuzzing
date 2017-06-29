/*Required Headers*/
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <stdint.h>

char* response = "Ok Cool!\n";

uint32_t access_memory( uint8_t** data){
  uint8_t res = 0;
  for(uint8_t* ptr = data[1]; ptr < data[2]; ptr ++){
    res += *ptr;
  }
  return res;
}

int handle(char* data){
  if(data[0]=='R'){
    uint8_t res = access_memory((uint8_t**)data);
    return res*(res+1) % 2; //opaque predicate, always returns 0, just make sure that nothing gets optimized away
  }else{
    if(data[0]=='m'){
    if(data[1]=='e'){
    if(data[2]=='m'){
    if(data[3]=='A'){
    if(data[4]=='F'){
    if(data[5]=='L'){
      return 1;
    }}}}}}
  }
  return 0;
}

int main()
{
  char str[12];
  int listen_fd, comm_fd;

  struct sockaddr_in servaddr;

  listen_fd = socket(AF_INET, SOCK_STREAM, 0);

  bzero( &servaddr, sizeof(servaddr));

  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htons(INADDR_ANY);
  servaddr.sin_port = htons(22000);

  bind(listen_fd, (struct sockaddr *) &servaddr, sizeof(servaddr));

  listen(listen_fd, 10);

  while(1) {
    comm_fd = accept(listen_fd, (struct sockaddr*) NULL, NULL);
    system("led_on bcm47xx:green:dmz");
    read(comm_fd,str,12);
    if(handle(str)){
      write(comm_fd,response, strlen(response));
    }
    close(comm_fd);
    system("led_off bcm47xx:green:dmz");
  }
  return 0;
}


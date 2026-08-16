#include<stdio.h>
#include<stdint.h>

void address_translation(uint32_t virtual_address){
    uint32_t page_number = virtual_address >> 12;
    uint32_t offset = virtual_address & 0xFFF;
    printf("[1A] Addr: 0x%08X -> Page: %u (0x%X), Offset: %u (0x%X)\n",virtual_address,page_number,page_number,offset,offset);


}

int main(){
    uint32_t address1=0x00000000;
    uint32_t address2=0x00000FFF;
    uint32_t address3=0x00001000;
    uint32_t address4=0x00003A2C;
    address_translation(address1);
    address_translation(address2);
    address_translation(address3);
    address_translation(address4);
    return 0;
}
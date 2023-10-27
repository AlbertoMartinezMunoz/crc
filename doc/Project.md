# CRC DOCUMENTATION

## TABLE OF CRC ALGORITHMS

| Algorithm          | CRC Type | Result     | Check      | Poly       | Init       | RefIn  | RefOut | XorOut     |
|:-------------------|:---------|:-----------|:-----------|:-----------|:-----------|:-------|:-------|:-----------|
| CRC-8              | uint8_t  | 0xF4       | 0xF4       | 0x07       | 0x00       | false  | false  | 0x00       |
| CRC-8/CDMA2000     | uint8_t  | 0xDA       | 0xDA       | 0x9B       | 0xFF       | false  | false  | 0x00       |
| CRC-8/DARC         | uint8_t  | 0x15       | 0x15       | 0x39       | 0x00       | true   | true   | 0x00       |
| CRC-8/DVB-S2       | uint8_t  | 0xBC       | 0xBC       | 0xD5       | 0x00       | false  | false  | 0x00       |
| CRC-8/EBU          | uint8_t  | 0x97       | 0x97       | 0x1D       | 0xFF       | true   | true   | 0x00       |
| CRC-8/I-CODE       | uint8_t  | 0x7E       | 0x7E       | 0x1D       | 0xFD       | false  | false  | 0x00       |
| CRC-8/ITU          | uint8_t  | 0xA1       | 0xA1       | 0x07       | 0x00       | false  | false  | 0x55       |
| CRC-8/MAXIM        | uint8_t  | 0xA1       | 0xA1       | 0x31       | 0x00       | true   | true   | 0x00       |
| CRC-8/ROHC         | uint8_t  | 0xD0       | 0xD0       | 0x07       | 0xFF       | true   | true   | 0x00       |
| CRC-8/WCDMA        | uint8_t  | 0x25       | 0x25       | 0x9B       | 0x00       | true   | true   | 0x00       |
| CRC-16/ARC         | uint16_t | 0xBB3D     | 0xBB3D     | 0x8005     | 0x0000     | true   | true   | 0x0000     |
| CRC-16/AUG-CCITT   | uint16_t | 0xE5CC     | 0xE5CC     | 0x1021     | 0x1D0F     | false  | false  | 0x0000     |
| CRC-16/BUYPASS     | uint16_t | 0xFEE8     | 0xFEE8     | 0x8005     | 0x0000     | false  | false  | 0x0000     |
| CRC-16/CCITT-FALSE | uint16_t | 0x29B1     | 0x29B1     | 0x1021     | 0xFFFF     | false  | false  | 0x0000     |
| CRC-16/CDMA2000    | uint16_t | 0x4C06     | 0x4C06     | 0xC867     | 0xFFFF     | false  | false  | 0x0000     |
| CRC-16/DDS-110     | uint16_t | 0x9ECF     | 0x9ECF     | 0x8005     | 0x800D     | false  | false  | 0x0000     |
| CRC-16/DECT-R      | uint16_t | 0x007E     | 0x007E     | 0x0589     | 0x0000     | false  | false  | 0x0001     |
| CRC-16/DECT-X      | uint16_t | 0x007F     | 0x007F     | 0x0589     | 0x0000     | false  | false  | 0x0000     |
| CRC-16/DNP         | uint16_t | 0xEA82     | 0xEA82     | 0x3D65     | 0x0000     | true   | true   | 0xFFFF     |
| CRC-16/EN-13757    | uint16_t | 0xC2B7     | 0xC2B7     | 0x3D65     | 0x0000     | false  | false  | 0xFFFF     |
| CRC-16/GENIBUS     | uint16_t | 0xD64E     | 0xD64E     | 0x1021     | 0xFFFF     | false  | false  | 0xFFFF     |
| CRC-16/KERMIT      | uint16_t | 0x2189     | 0x2189     | 0x1021     | 0x0000     | true   | true   | 0x0000     |
| CRC-16/MAXIM       | uint16_t | 0x44C2     | 0x44C2     | 0x8005     | 0x0000     | true   | true   | 0xFFFF     |
| CRC-16/MCRF4XX     | uint16_t | 0x6F91     | 0x6F91     | 0x1021     | 0xFFFF     | true   | true   | 0x0000     |
| CRC-16/MODBUS      | uint16_t | 0x4B37     | 0x4B37     | 0x8005     | 0xFFFF     | true   | true   | 0x0000     |
| CRC-16/RIELLO      | uint16_t | 0x63D0     | 0x63D0     | 0x1021     | 0xB2AA     | true   | true   | 0x0000     |
| CRC-16/T10-DIF     | uint16_t | 0xD0DB     | 0xD0DB     | 0x8BB7     | 0x0000     | false  | false  | 0x0000     |
| CRC-16/TELEDISK    | uint16_t | 0x0FB3     | 0x0FB3     | 0xA097     | 0x0000     | false  | false  | 0x0000     |
| CRC-16/TMS37157    | uint16_t | 0x26B1     | 0x26B1     | 0x1021     | 0x89EC     | true   | true   | 0x0000     |
| CRC-16/USB         | uint16_t | 0xB4C8     | 0xB4C8     | 0x8005     | 0xFFFF     | true   | true   | 0xFFFF     |
| CRC-16/X-25        | uint16_t | 0x906E     | 0x906E     | 0x1021     | 0xFFFF     | true   | true   | 0xFFFF     |
| CRC-16/XMODEM      | uint16_t | 0x31C3     | 0x31C3     | 0x1021     | 0x0000     | false  | false  | 0x0000     |
| CRC-A              | uint16_t | 0xBF05     | 0xBF05     | 0x1021     | 0xC6C6     | true   | true   | 0x0000     |
| CRC-32             | uint32_t | 0xCBF43926 | 0xCBF43926 | 0x04C11DB7 | 0xFFFFFFFF | true   | true   | 0xFFFFFFFF |
| CRC-32/BZIP2       | uint32_t | 0xFC891918 | 0xFC891918 | 0x04C11DB7 | 0xFFFFFFFF | false  | false  | 0xFFFFFFFF |
| CRC-32/JAMCRC      | uint32_t | 0x340BC6D9 | 0x340BC6D9 | 0x04C11DB7 | 0xFFFFFFFF | true   | true   | 0x00000000 |
| CRC-32/MPEG-2      | uint32_t | 0x0376E6E7 | 0x0376E6E7 | 0x04C11DB7 | 0xFFFFFFFF | false  | false  | 0x00000000 |
| CRC-32/POSIX       | uint32_t | 0x765E7680 | 0x765E7680 | 0x04C11DB7 | 0x00000000 | false  | false  | 0xFFFFFFFF |
| CRC-32/SATA        | uint32_t | 0xCF72AFE8 | 0xCF72AFE8 | 0x04C11DB7 | 0x52325032 | false  | false  | 0x00000000 |
| CRC-32/XFER        | uint32_t | 0xBD0BE338 | 0xBD0BE338 | 0x000000AF | 0x00000000 | false  | false  | 0x00000000 |
| CRC-32C            | uint32_t | 0xE3069283 | 0xE3069283 | 0x1EDC6F41 | 0xFFFFFFFF | true   | true   | 0xFFFFFFFF |
| CRC-32D            | uint32_t | 0x87315576 | 0x87315576 | 0xA833982B | 0xFFFFFFFF | true   | true   | 0xFFFFFFFF |
| CRC-32Q            | uint32_t | 0x3010BF7F | 0x3010BF7F | 0x814141AB | 0x00000000 | false  | false  | 0x00000000 |

## ARCHITECTURE

### UML Class Diagram

![Image cannot be displayed](./architecture.png "CRC UML Template Desing Pattern")
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//#region STRUCTS
//#region BMP HEADER
/**
 * Estrutura para o Header de arquivo BMP
 */
typedef struct {
    //#region FILE HEADER
    // filetype | tipo do arquivo
    // tamanho: Windows & OS/2: 2 char = 4 bytes
    char type[3];
    // File size in bytes | tamanho do arquivo em bytes
    // tamanho: Windows & OS/2: 4 bytes
    unsigned int size;
    // Not used | valor reservado do BMP
    // tamanho: Windows & OS/2: 2 bytes
    unsigned short reserved1;
    // Not used | valor reservado do BMP
    // tamanho: Windows & OS/2: 2 bytes
    unsigned short reserved2;
    // Offset to image data in bytes from beginning of file | offset para o inicio da imagem em bytes
    // tamanho: Windows & OS/2: 4 bytes
    unsigned long offset;
    //#endregion

    //#region DIB HEADER
    // DIB Header size in bytes | tamanho do header do DIB em bytes
    // tamanho: Windows & OS/2: 4 bytes
    unsigned int dib_header_size;
    // Width of the image | tamnho da imagem
    // tamanho: Windows: 4 bytes | OS/2: 2 bytes
    long  width_px;
    // Height of image | altura da imagem
    // tamanho: Windows: 4 bytes | OS/2: 2 bytes
    long  height_px;
    // Number of color planes | numero de planos de cores
    // tamanho: Windows & OS/2: 2 bytes
    unsigned short num_planes;
    // Bits per pixel | bites por pixel
    // tamanho: Windows & OS/2: 2 bytes
    unsigned short bits_per_pixel;
    // Compression type | type de compressão
    // tamanho: Windows: 4 bytes
    unsigned int compression;
    // Image size in bytes | tamanho da imagem em bytes
    // tamanho: Windows: 4 bytes
    unsigned int image_size_bytes;
    // Pixels per meter horizontal | resolução por pixel horizontal
    // tamanho: Windows: 4 bytes
    long  x_resolution_ppm;
    // Pixels per meter vertical | resolução por pixel horizontal
    // tamanho: Windows: 4 bytes
    long  y_resolution_ppm;
    // Number of colors | numero de cores, 0 significa o máximo de cor, igual á 2^bites por pixel
    // tamanho: Windows: 4 bytes
    unsigned long num_colors;
    // Important colors | numero de cores imporantes, 0 indica todas as cores serem importantes
    // tamanho: Windows: 4 bytes
    unsigned long important_colors;
    //#endregion
} BMPHeader;
//#endregion

//#region RGB COLOR
/**
 * estrutura de cor para arquivo BMP
 */
typedef struct color_rgb {
    unsigned char r,g,b,alpha;
} ColorRGB;
//#endregion
//#endregion

//#region FUNCTIONS
//#region BASIC FUNCTIONS
//#region LEITOR ENTRADA
//copy paste
/**
 * Leitor FUNCIONAL DE STDIN OU ARQUIVO
 * @param file entrada
 * @return string lida
 */
char *readline(FILE *file) {
    // string base
    char *string = 0;
    // tamanho da string
    int pos = 0;
    // leitura de
    do {
        // alocação da memória
        string = (char *) realloc(string, (pos + 1) * sizeof(char));
        // leitura do caractére
        string[pos] = (char) fgetc(file);
        // verificação se é o fim da leitura ou da linha
    } while ((string[pos++] != '\n') && ! feof(file));
    // adiciona terminador nulo
    string[--pos] = '\0';
    // retorna a string lida
    return string;
}
//#endregion

/*//#region STRING SPLIT
char *strSplit(char *string, const char *param) {
    short i = 0,paramSize = 0;
    char *tempString = calloc(strlen(param),sizeof(char));
    while(i != strlen(string)) {
        if(paramSize == strlen(param)) {
            if(!strcmp(tempString,param)) {
                break;
            } else {
                paramSize = 0;
                i++;
            }
        }else {
            tempString[paramSize] = string[i+paramSize];
            paramSize++;
        }
    }
    i -= paramSize;
    char *stringSplit = malloc(i * sizeof(char));
    while(i > -1){
        stringSplit[--i] = string[i];
    }
    return stringSplit;
}
//#endregaion*/

//#endregion

//#region LITTLE ENDIANS, BYTE & BIT
//#region READ LITTLE ENDIANS BIT
/**
 * Leitura de um byte em little endians, bit por bit
 * @param file arquivo a ser lido
 * @return bits lidos em um array
 */
unsigned char *readLittleEndiansBits(FILE *file) {
    // buffer e bit array
    unsigned char buf[1], *bitArray = calloc(8,sizeof(char));;
    // leitura do arquivo, byte por byte, 1 byte por vez
    fread(buf, 1, 1, file);
    // transformação em bits
    for (int i = 0; i < 9; i++) {
        bitArray[i] = floor((double) buf[0]/pow(2,i));
    }

    return bitArray;
}
//#endregion

//#region BITS TO BYTE
/**
 * Transforma 8 bits em um byte
 * @param bitArray array dos bits, 0's e 1's
 * @return bit transformado para um byte
 */
unsigned char bitsToByte(unsigned char bitArray[8]) {
    unsigned char result = 0;
    for(int i = 0; i < 9; i++) {
        result += pow(2,i * bitArray[i]);
    }
    return result;
}
//#endregion

//#region BYTE TO BIT
/**
 * Transforma byte em 8 bits
 * @param Byte byte a ser transformado
 * @return array de 8 bits
 */
unsigned char *byteToBits(unsigned char Byte) {
    // bit array
    unsigned char *bitArray = calloc(8,sizeof(char));
    // transformação em bits
    for (int i = 0; i < 9; i++) {
        bitArray[i] = floor((double) Byte/pow(2,i));
    }
    return bitArray;
}
//#endregion

//#region READ LITTLE ENDIANS
/**
 * Leitura do arquivo em little endians
 * @param file arquivo a ser lido
 * @param qnt quantidade de bytes a serem lidos
 * @return bytes lidos transformados em número
 */
long long readLittleEndians(FILE *file,char qnt) {
    // buffer
    unsigned char buf[qnt];
    // resultado
    long long result = 0;
    // leitura do arquivo, byte por byte, 1 byte por vez
    fread(buf, 1, qnt, file);
    // transformação em número
    for (int i = qnt - 1; i >= 0; i--) {
        result = (result << 8) | (long long) buf[i];
    }

    return result;
}
//#endregion

//#region WRITE LITTLE ENDIANS
/**
 * Escrita do arquivo em little endians
 * @param file arquivo a ser escrito
 * @param qnt quantidade de bytes a serem escritos
 * @param fileWrite arquivo a ser escrito
 */
void writeLittleEndians(long long item,FILE *file,short qnt) {
    // buffer
    unsigned char buf[qnt];
    // transformação em byte
    for (int i = 0; i < qnt; i++) {
        buf[i] =   (item >> (i * 8)) & 0xFF;
    }
    //escrita no arquivo byte por byte, 1 byte por vez
    fwrite(buf, 1, qnt, file);
}
//#endregion
//#endregion

//#region BMP HEADER
//#region BMP HEADER READER
/**
 * Leitor de header de arquivo BMP
 * @param file arquivo a ser lido
 * @param bmpHeader header criado
 * @return número de erros
 */
char bmpHeaderReader(FILE *file, BMPHeader *bmpHeader) {
    //#region FILE HEADER
    // tipo do arquivo
    char type[3] = {'\0', '\0', '\0'};
    fread(&type,1,2,file);
    strcpy(bmpHeader->type,type);
    // verificação se arquivo é BM
    if(strcmp(bmpHeader->type,"BM") != 0)
        return 1;
    // tamnho do arquivo
    bmpHeader->size = (unsigned int) readLittleEndians(file,4);
    // valor reservado 1
    bmpHeader->reserved1 = (unsigned short) readLittleEndians(file,2);
    //valor reservado 2
    bmpHeader->reserved2 = (unsigned short) readLittleEndians(file,2);
    // offset até valor da imagem
    bmpHeader->offset = (unsigned long) readLittleEndians(file,4);
    //#endregion

    //#region DIB HEADER
    // tamanho do dib header, size == 40 windows, size == 2 OS/2
    bmpHeader->dib_header_size =(unsigned int) readLittleEndians(file,4);
    //#endregion

    // Windows Header
    if(bmpHeader->dib_header_size == 40) {
        // largura
        bmpHeader->width_px = (long) readLittleEndians(file,4);
        // altura
        bmpHeader->height_px = (long) readLittleEndians(file,4);
        // numero de planos
        bmpHeader->num_planes =  (unsigned short) readLittleEndians(file,2);
        // bits por pixel
        bmpHeader->bits_per_pixel = (unsigned short) readLittleEndians(file,2);
        // tipo de compressão usada
        bmpHeader->compression = (unsigned int) readLittleEndians(file, 4);
        // tamanho da imagem em bytes
        bmpHeader->image_size_bytes = (unsigned int) readLittleEndians(file, 4);
        // resolução horizontal em pixel por metro
        bmpHeader->x_resolution_ppm = (long) readLittleEndians(file, 4);
        // resolução vertical em pixel por metro
        bmpHeader->y_resolution_ppm = (long) readLittleEndians(file, 4);
        // numero de cores usadas
        bmpHeader->num_colors = (unsigned long) readLittleEndians(file, 4);
        // numero de cores importantes
        bmpHeader->important_colors = (unsigned long) readLittleEndians(file, 4);
    // OS/2 Header
    } else if(bmpHeader->dib_header_size == 12) {
        // largura
        bmpHeader->width_px = (long) readLittleEndians(file,2);
        // altura
        bmpHeader->height_px = (long) readLittleEndians(file,2);
        // numero de planos
        bmpHeader->num_planes =  (unsigned short) readLittleEndians(file,2);
        // bits por pixel
        bmpHeader->bits_per_pixel = (unsigned short) readLittleEndians(file,2);
    }
    return 0;
}
//#endregion

//#region BMP HEADER WRITER
/**
 * ESCREVE UM HEADER DE ARQUIVO BMP
 * @param file arquivo a ser escrito
 * @param bmpHeader header a ser escrito
 */
void bmpHeaderWriter(FILE *file, BMPHeader *bmpHeader) {
    //#region FILE HEADER
    // tipo do arquivo
    fwrite(bmpHeader->type,1,2,file);
    // tamanho do arquivo
    writeLittleEndians(bmpHeader->size,file,4);
    // valor reservado 1
    writeLittleEndians(bmpHeader->reserved1,file,2);
    // valor reservado 2
    writeLittleEndians(bmpHeader->reserved2,file,2);
    // offset
    writeLittleEndians(bmpHeader->offset,file,4);
    //#endregion

    //#region DIB HEADER
    // Dib header, size == 40 windows, size == 12 os/2
    writeLittleEndians(bmpHeader->dib_header_size,file,4);
    //#endregion

    // WINDOWS HEADER
    if(bmpHeader->dib_header_size == 40) {
        // largura
        writeLittleEndians(bmpHeader->width_px,file,4);
        // altura
        writeLittleEndians(bmpHeader->height_px,file,4);
        // numero de planos
        writeLittleEndians(bmpHeader->num_planes,file,2);
        // bits por pixel
        writeLittleEndians(bmpHeader->bits_per_pixel,file,2);
        // tipo de compressão
        writeLittleEndians(bmpHeader->compression,file,4);
        // tamanho da imagem em bytes
        writeLittleEndians(bmpHeader->image_size_bytes,file,4);
        // resolução horizontal pixel / metro
        writeLittleEndians(bmpHeader->x_resolution_ppm,file,4);
        // resolução vertical pixel / metro
        writeLittleEndians(bmpHeader->y_resolution_ppm,file,4);
        // numero de cores usadas
        writeLittleEndians(bmpHeader->num_colors,file,4);
        // numero de cores importantes
        writeLittleEndians(bmpHeader->important_colors,file,4);
    // OS/2 HEADER
    } else if(bmpHeader->dib_header_size == 12) {
        // largura
        writeLittleEndians(bmpHeader->width_px,file,2);
        // altura
        writeLittleEndians(bmpHeader->height_px,file,2);
        // numero de planos
        writeLittleEndians(bmpHeader->num_planes,file,2);
        // bits por pixel
        writeLittleEndians(bmpHeader->bits_per_pixel,file,2);
    }
}
//#endregion

//#region BMP HEADER PRINTER
/**
 * Apresenta o BMP header em printf
 * @param bmpHeader BMP Header a ser apresentado
 */
void printBMPHeader(BMPHeader *bmpHeader) {
    printf("CABEÇALHO\n");
    printf("Iniciais: %s\n", bmpHeader->type);
    printf("tamanho do arquivo: %u bytes\n", bmpHeader->size);
    printf("Reservado: %d\n",bmpHeader->reserved1 + bmpHeader->reserved2);
    printf("Deslocamento, em bytes, para o inicio da area de dados: %ld bytes\n", bmpHeader->offset);
    printf("Tamanho em bytes do segundo cabecalho: %d bytes\n", bmpHeader->dib_header_size);
    printf("Resolucao: %ld\n", bmpHeader->width_px * bmpHeader->height_px);
    printf("largura: %ld pixels\n", bmpHeader->width_px);
    printf("altura: %ld pixels\n", bmpHeader->height_px);
    printf("Numero  de planos: %d\n", bmpHeader->num_planes);
    printf("Bits por pixel: %d\n", bmpHeader->bits_per_pixel);
    if (bmpHeader->dib_header_size == 40) {
        printf("Compressao usada: %d\n", bmpHeader->compression);
        printf("Tamanho imagem: %u bytes\n", bmpHeader->image_size_bytes);
        printf("Resolucao horizontal: %ld\n", bmpHeader->x_resolution_ppm);
        printf("Resolucao Vertical: %ld\n", bmpHeader->y_resolution_ppm);
        printf("Numero de cores usadas: %ld cores\n", bmpHeader->num_colors);
        printf("Numero de cores importantes: %ld cores\n",bmpHeader->important_colors);
    }
}
//#endregion
//#endregion

//#region COLOR RGB
//#region READ COLOR RGB
/**
 * Leitor de cor RGB de acordo com BMP
 * @param file arquivo a ser lido
 * @return Struct ColorRGB preenchido;
 */
ColorRGB readColorRGB(FILE *file) {
    // cria o struct
    ColorRGB colorsRGB;
    // obtem o RGB e o lixo conjunto
    colorsRGB.b = (unsigned char) readLittleEndians(file,1);
    colorsRGB.g = (unsigned char) readLittleEndians(file,1);
    colorsRGB.r = (unsigned char) readLittleEndians(file,1);
    colorsRGB.alpha = (unsigned char) readLittleEndians(file,1);
    // retorna o struct recém criado
    return colorsRGB;
}
//#endregion

//#region WRITE COLOR RGB
/**
 * Ecreve uma entrada de cor RGB de acordo com BMP
 * @param file arquivo a ser escrito
 * @param colorsRGB cor RGB a ser escrita
 */
void writeColorRGB(FILE *file, ColorRGB colorsRGB) {
    // escreve RGB e o lixo conjunto
    writeLittleEndians(colorsRGB.b,file,1);
    writeLittleEndians(colorsRGB.g,file,1);
    writeLittleEndians(colorsRGB.r,file,1);
    writeLittleEndians(colorsRGB.alpha,file,1);
}
//#endregion

//#region PRINT COLOR RGB
/**
 * Escreve em printf a cor RGB
 * @param colorsRGB cor RGB a ser escrita
 * @param num numero da paleta
 */
void printColorRGB(ColorRGB colorsRGB,long long num) {
    printf("Paleta[%lld]: R:%d  G:%d  B:%d\n",num,colorsRGB.r,colorsRGB.g,colorsRGB.b);
}
//#endregion
//#endregion
//#endregion

int main() {
    //#region ENTRADA
    // nome do arquivo, extensão e tipo do filtro
    char *filename  = readline(stdin), *rest = strrchr(filename,'.'),*filterType = readline(stdin);
    //#endregion

    // Verifica se estensão é do tipo BMP
    if(!strcasecmp(rest,".bmp")) {
        // Abre o arquivo para leitura binaria com nome baseado na entrada
        FILE *file = fopen(filename, "rb");
        // verifica se existe arquivo
        if (file != NULL) {
            // Cria Struct do header do bitmap
            BMPHeader *bmpHeader = malloc(1 * sizeof(BMPHeader));
            // Verifica se há erros na entrada do bitmap
            if(!bmpHeaderReader(file, bmpHeader)) {
                //#region BMP HEADER
                // apresenta o header do bitmap
                printBMPHeader(bmpHeader);
                //#region CRIAÇÃO ARQUIVO ESCRITA
                // cria o local do nome do segundo arquivo
                char * filewrite = malloc(strlen(filename) * sizeof(char));
                // copia o nome completo do segundo arquivo
                strcpy(filewrite,filename);
                // separa o nome da extensão, apendiciona a parte extra do nome e depois re-insere a extensão
                filewrite = strcat(strcat(strtok(filewrite,"."),
                                          !strcmp(filterType,"1") ? "Negativo" : "PretoBranco"),rest);
                // cria e abre o arquivo para escrita binaria
                FILE *filew = fopen(filewrite, "wb");
                //#endregion
                // escreve o header do bitmap do primeiro arquivo no segundo arquivo
                bmpHeaderWriter(filew,bmpHeader);
                //#endregion

                //#region COLOR RGB
                // cria variável com valor baseado na quantidade de cores existentes
                long long size = !bmpHeader->num_colors ?
                        pow(2,bmpHeader->bits_per_pixel) : bmpHeader->num_colors;
                // cria o vetor de cores de acordo com size
                ColorRGB *colorsRGB = calloc(size,sizeof(ColorRGB));
                // repetição para adicionar todas as cores ao vetor
                printf("PALETA ORIGINAL:\n");
                for (long long i = 0; i < size; i++) {
                    // adiciona cor lida ao vetor
                    colorsRGB[i] = readColorRGB(file);
                    // apresenta a cor recém lida
                    printColorRGB(colorsRGB[i],i);
                    // filtro negativo
                    if(!strcmp(filterType,"1")) {
                        colorsRGB[i].r = abs(colorsRGB[i].r - 255);
                        colorsRGB[i].g = abs(colorsRGB[i].g - 255);
                        colorsRGB[i].b = abs(colorsRGB[i].b - 255);
                    // filtro grayscale
                    } else {
                        int media  = (colorsRGB[i].r + colorsRGB[i].g + colorsRGB[i].b)/3;
                        colorsRGB[i].r = media;
                        colorsRGB[i].g = media;
                        colorsRGB[i].b = media;
                    }
                }
                // repetição para escrever as cores com filtros e apresentá-las
                printf("PALETA NOVA:\n");
                for (long long i = 0; i < size; i++) {
                    // apresenta a cor recém lida
                    printColorRGB(colorsRGB[i],i);
                    // escreve no segundo arquivo a cor recém lida
                    writeColorRGB(filew,colorsRGB[i]);

                }
                // libera o vetor após utilizado
                free(colorsRGB);
                //#endregion

                //#region MATRIZ DE INFORMAÇÂO & FREE
                // A matriz tem tamanho de altura (linha)  X largura (coluna)
                // dependendo da quantidades de bits por pixel há a mudança da leitura de bytes
                // cria a matriz que irá conter todos os valores, o maior deles possível sendo 2^32
                long long **mat = calloc(bmpHeader->height_px,sizeof(long long *)),
                        // cria a varável que contém a quantidade de bytes que são lixo
                        // para manter a padronização de largura % 4 == 0
                        junkBytes = bmpHeader->width_px % 4 == 0 ? 0 : 4 - (bmpHeader->width_px % 4),
                        // a quantidade de bytes ou bits lidos para cada pixel ou indíce no vetor
                        numBytes = bmpHeader->bits_per_pixel/8;
                // repetição por altura
                for(int i = 0; i < bmpHeader->height_px; i++) {
                    // variável da soma, máximo é 2^32 * altura
                    unsigned long long sum = 0;
                    // alloca memoria a cada item da coluna
                    mat[i] = calloc(bmpHeader->width_px + junkBytes,sizeof(long long));
                    // repetição por largura + junkBytes, caso largura % 4 != 0
                    for(int j = 0; j < bmpHeader->width_px + junkBytes; j++) {
                        // insere a quantidade de bytes necessários a serem lidos no índice da matriz
                        mat[i][j] = readLittleEndians(file,numBytes);
                        // verifica se o byte ou bits lido é lixo
                        if(j >= bmpHeader->width_px)
                            sum -= 1;
                        else
                            sum += mat[i][j];
                        // escreve no segundo arquivo o valor da matriz
                        writeLittleEndians(mat[i][j], filew,numBytes);
                    }
                    free(mat[i]);
                    // apresenta a dos valores da linha da matriz
                    printf("Soma Linha %d: %llu\n",i,sum);
                }
                // libera a matriz
                free(mat);
                // fecha o segundo arquivo
                fclose(filew);
                //#endregion
            } else {
                printf("Arquivo nao eh do formato BMP\n");
            }
            // libera o header
            free(bmpHeader);
            // fecha o arquivo principal
            fclose(file);
        } else {
            printf("Erro no arquivo\n");
        }
    } else {
        printf("Arquivo nao eh do formato BMP\n");
    }
    // libera o nome do arquivo e o tipo do filtro
    free(filename);
    free(filterType);
    return 0;
}

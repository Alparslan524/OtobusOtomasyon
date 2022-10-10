#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int i=1,j=1,k=0,l=1,m=1,n=1,b=1,v=1,vv=1,z=0,zz=1,e=0,r=0,w=0,t=0,y=0,u=0,uu=0,ii=0;
int p=0,o=0,s=0,ss=0,f=0,ff=0,g=0,h=0,hh=0,nn=0,nnn=0,xx=1,q=0,qq=0,a=0,c=0,d=0,cc=0,dd=0,rr=0;
int x;
char ad[100][20];
char soyad[100][20];
int seferno_secim,seferno_secim2,seferno_secim3;
int kapasite[100];
char model[100][3];
int secim,secim2,secim3;
int secim_otobusno[100];
int baslangic_saati_dakika[100];
int baslangic_saati_saat[100];
int bitis_saati[100];
char sehir_baslangic[100][15];
char sehir_varis[100][15];
int hasilat[100];
char hex_karakter[16] = { '0','1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C',  'D',  'E',  'F'};
char rastgele_seferno[6];
char sefer_no[100][6];
int koltuk_secim[100];
char onay;
char alfabe_rakam[35]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','R','S','T','U','V','Y','Z','Q','W','1','2','3','4','5','6','7','8','9','0'};
char rastgele_rez_no[8];
char rez_no[100][8];
char istenilen_rez_no[8];
float bilet[100];

void ana_menu()
{
    printf("\n\n\n");
    printf("\t\t\t\t\t\t****************\n");
    printf("\t\t\t\t\t\t*   Ana Menu   *\n");
    printf("\t\t\t\t\t\t****************\n");
    printf("\t\t\t\t\t\t1. Firma Girisi\n");
    printf("\t\t\t\t\t\t2. Musteri Girisi\n");
    printf("\t\t\t\t\t\t3. Cikis\n");
    printf("\t\t\t\t\t\tLutfen Secim Yapiniz: ");
    scanf("%d",&secim);
    system("cls");
    switch(secim)
    {
    case 1:
        firma_menu();
        break;
    case 2:
        musteri_menu();
        break;
    case 3:
        return 0;
        break;
    default:
        printf("\tYanlis Secim!!!");
        ana_menu();
    }

}

void firma_menu()
{
    printf("\n\n\n");
    printf("\t\t\t\t\t\t1. Otobus Ekle\n");
    printf("\t\t\t\t\t\t2. Sefer Bilgisi Ekle\n");
    printf("\t\t\t\t\t\t3. Koltuk/Sefer Bilgisi\n");
    printf("\t\t\t\t\t\t4. Bir Ust Menu\n");
    printf("\t\t\t\t\t\tLutfen Secim Yapiniz: ");
    scanf("%d",&secim2);
    system("cls");
    switch(secim2)
    {
        case 1:
            firma_menu_otobusekle();
            break;
        case 2:
            firma_menu_seferbilgiekle();
            break;
        case 3:
            firma_menu_koltuk();
            break;
        case 4:
            ana_menu();
            break;
        default:
            printf("\tYanlis Secim!!!");
            firma_menu();
    }




}

void firma_menu_otobusekle()
{

    printf("Kapasite: ");
    scanf("%d",&kapasite[i]);
    if(kapasite[i]<=0)
        {
            printf("Sifir Veya Eksi Deger Giremezsiniz!!\n");
            firma_menu_otobusekle();
        }
    i++;
    printf("Model: ");
    scanf("%s",&model[j]);
    j++;
    printf("\n");
    printf("%d Nolu Otobusun Ozellikleri: \n",i-1);
    printf("Kapasite: %d\n",kapasite[i-1]);
    printf("Model: %s\n",model[j-1]);
    if(kapasite[i-1]>0 && kapasite[i-1]<=30)
        {
            x=2;
            printf("Otobus Kisa yola Gidiyor. Bu Yuzden %d Personel vardir\n\n",x);
        }
    else
        {
            x=3;
            printf("Otobus Uzun yola Gidiyor. Bu Yuzden %d Personel vardir\n\n",x);
        }

     firma_menu();
}

void firma_menu_seferbilgiekle()
{

    seferbilgi_sefer_noekle();
    firma_menu_seferbilgisi_otobusno();
    sefer_baslangic_saati();
    sehir_1();
    sehir_2();
    istenilen_hasilat();
    firma_menu();
}

void seferbilgi_sefer_noekle()
{
    srand(time(NULL));
    for (size_t w= 0; w< 100; w++)
    {

        rastgele_seferno[0] = '1';
        rastgele_seferno[1] = '6';
        rastgele_seferno[2] = hex_karakter[rand() % 16];
        rastgele_seferno[3] = hex_karakter[rand() % 16];
        rastgele_seferno[4] = hex_karakter[rand() % 16];
        rastgele_seferno[5] = hex_karakter[rand() % 16];

    }
        for(r=0;r<6;r++)
        {
            sefer_no[e][r]=rastgele_seferno[r];
        }
    e++;

        for(uu=0;uu<6;uu++)
        {
            printf("%c",sefer_no[u][uu]);
        }
        printf(" Numarali Sefer Icin ");
        u++;



}

void firma_menu_seferbilgisi_otobusno()
{
    printf("Hangi Otobusu Istiyorsunuz?: ");
    scanf("%d",&secim_otobusno[p]);



   if(secim_otobusno[p]>=i)
    {
        printf("Bu Noya Sahip Otobus Yoktur\n");
        firma_menu_seferbilgisi_otobusno();
    }
    p++;
}

void sefer_baslangic_saati()
{
    c:
    printf("Sefer Saatini Giriniz: ");
    scanf("%d",&baslangic_saati_saat[l]);
    if(baslangic_saati_saat[l]<0 || baslangic_saati_saat[l]>23)
    {
        printf("Yanlis Saat Girdiniz!!\n");
        goto c;
    }
    a:
    printf("Sefer Dakikasini Giriniz: ");//M
    scanf("%d",&baslangic_saati_dakika[m]);
    if(baslangic_saati_dakika[m]<0 || baslangic_saati_dakika[m]>60)
    {
        printf("Yanlis dakika Girdiniz!!\n");
        goto a;
    }
    else
        if(baslangic_saati_dakika[m]!=16)
    {
        printf("Sefer Bu Saatte Baslayamaz!\n");
        baslangic_saati_dakika[m]=16;
        printf("Sefer Dakikasi %d Olarak Degistirildi\n",baslangic_saati_dakika[m]);
    }
    printf("Sefer Baslama Saati: %d%d\n",baslangic_saati_saat[l],baslangic_saati_dakika[m]);
    sefer_bitis_saati();
}

void sefer_bitis_saati()
{
    d:
    printf("Tahmini Varis Saatini Giriniz: ");
    scanf("%d",&bitis_saati[n]);
    if(bitis_saati[n]<0 || bitis_saati[n]>60)
    {
        printf("Yanlis Saat Girdiniz!!\n");
        goto d;
    }

    if(kapasite[secim_otobusno[p]]<=30 && bitis_saati[n]-baslangic_saati_saat[l]>4 )//sadece uzun yol
    {
            printf("Bu Otobus Sadece Kisa Yola Gidebilir.Tekrar Saat Giriniz.\n");
            sefer_baslangic_saati();
    }
    l++;
    m++;
    n++;
}

void sehir_1()
{
    printf("Otobus Nereden Hareket Edecek?: ");
    scanf("%s",&sehir_baslangic[v]);
}

void sehir_2()
{
    printf("Otobus Nereye Gidecek?: ");
    scanf("%s",&sehir_varis[vv]);
    v++;
    vv++;
}

void istenilen_hasilat()
{
    printf("Bu Yolculuktan Istenilen Hasilat Nedir?: ");
    scanf("%d",&hasilat[z]);
    z++;
}

void firma_menu_koltuk()
{
     for(u=0;u<e;u++)
    {
        printf("%d-> ",u);
        for(uu=0;uu<6;uu++)
        {
            printf("%c",sefer_no[u][uu]);
        }
        printf("\n");
    }
    printf("Sefer no?: ");
    scanf("%d",&seferno_secim);

    bilgilendirme();
}

void bilgilendirme()
{
    printf("\n\t----Sefer Bilgileri----\n");
    printf("Toplam Hasilat %d\n",hasilat[seferno_secim]);

    printf("%s Sehrinden ",sehir_baslangic[seferno_secim+1]);
    printf("%s Sehrine ",sehir_varis[seferno_secim+1]);

    printf("%d-%d Saatleri Arasinda Gerceklesecektir\n",baslangic_saati_saat[seferno_secim+1],bitis_saati[seferno_secim+1]);
    for(u=seferno_secim;u<e;u++)
    {
        for(uu=0;uu<6;uu++)
        {
            printf("%c",sefer_no[u][uu]);
        }
        printf(" Nolu Sefer ");
        break;
    }
    printf("%d Nolu Otobus ile Gerceklesecektir\n",secim_otobusno[seferno_secim]);
    firma_menu();
}

void musteri_menu()
{
    printf("\n\n\n");
    printf("\n\t\t\t\t\t\t1.Seferleri Listele\n");
    printf("\t\t\t\t\t\t2.Sefer Rezervasyon Yap\n");
    printf("\t\t\t\t\t\t3.Rezervasyon Goster\n");
    printf("\t\t\t\t\t\t4.Bir Ust Menuye Don\n");
    printf("\t\t\t\t\t\tLutfen Secim Yapiniz: ");
    scanf("%d",&secim3);
    system("cls");
    switch(secim3)
    {
    case 1:
        musteri_menu_seferlistele();
        break;
    case 2:
        musteri_menu_rezervasyon_yap();
        break;

    case 3:
        rezervasyon_goster();
        break;

    case 4:
        ana_menu();
        break;
    default:
        printf("Yanlis Secim!!");
        musteri_menu();






}


}

void musteri_menu_seferlistele()
{
    for(u=0;u<e;u++)
    {
        printf("%d-> ",u);
        for(uu=0;uu<6;uu++)
        {
            printf("%c",sefer_no[u][uu]);
        }
        printf("\n");
    }
    printf("Bilgilerini Gormek Istediginiz Sefer Noyu Seciniz: ");
    scanf("%d",&seferno_secim2);

    printf("Bilet: %f TL",bilet[ii-1]);
    printf("%d Nolu Otobus ile ",secim_otobusno[seferno_secim2]);
    printf("%s Sehrinden ",sehir_baslangic[seferno_secim2+1]);
    printf("%s Sehrine ",sehir_varis[seferno_secim2+1]);
    printf("%d-%d Saatleri Arasinda ",baslangic_saati_saat[seferno_secim2+1],bitis_saati[seferno_secim2+1]);
    printf("Yolculuk Gerceklestirilecektir\n");

    musteri_menu();

}

void musteri_menu_rezervasyon_yap()
{
     for(u=0;u<e;u++)
    {
        printf("%d-> ",u);
        for(uu=0;uu<6;uu++)
        {
            printf("%c",sefer_no[u][uu]);
        }
        printf("\n");
    }

    printf("Sefer Seciniz:  ");
    scanf("%d",&seferno_secim3);

    printf("Adiniz: ");
    scanf("%s",&ad[h]);
    printf("Soy adiniz: ");
    scanf("%s",&soyad[hh]);
    h++;
    hh++;
    rezervasyon_koltuk_satin_alma();

}

void rezervasyon_koltuk_satin_alma()
{
    char koltuk[kapasite[i-1]][4];
    rr=0;
    xx=1;
    for(nn=0;nn<(kapasite[i-1]/4);nn++)
    {
        for(nnn=0;nnn<4;nnn++)
        {
            printf(" [%d] \t",xx);
            xx++;
        }
        printf("\n");
    }

    printf("Dolu Olan kotuklar: ");
    for(qq=0;qq<q;qq++)
    {
        printf("%d ",koltuk_secim[qq]);
    }

    aa:
    printf("\nHangi Koltugu Almak istiyorsunuz?: ");
    scanf("%d",&koltuk_secim[q]);

    for(qq=0;qq<q;qq++)
    {
        if(koltuk_secim[q]==koltuk_secim[qq])
        {
            printf("Sectiginiz Koltuk Doludur");
            goto aa;
        }
    }
    q++;
    aaa:
    printf("%d Nolu Koltugu Aliyorsunuz. Onayliyor musunuz?",koltuk_secim[q-1]);
    printf(" E/H --> ");
    scanf("%s",&onay);
    switch(onay)
    {
    case 'E':
        rezervasyon_no_olusturma();
        break;
    case 'H':
        q--;
        musteri_menu();
        break;
    default:
        printf("Hatali Secim");
        goto aaa;
    }




}

void rezervasyon_no_olusturma()
{
        srand(time(NULL));
    for (size_t s= 0; s< 100; s++)
    {
        rastgele_rez_no[0] = alfabe_rakam[rand() % 35];
        rastgele_rez_no[1] = alfabe_rakam[rand() % 35];
        rastgele_rez_no[2] = alfabe_rakam[rand() % 35];
        rastgele_rez_no[3] = alfabe_rakam[rand() % 35];
        rastgele_rez_no[4] = alfabe_rakam[rand() % 35];
        rastgele_rez_no[5] = alfabe_rakam[rand() % 35];
        rastgele_rez_no[6] = alfabe_rakam[rand() % 35];
        rastgele_rez_no[7] = alfabe_rakam[rand() % 35];

    }
       cc++;

        for(o=0;o<8;o++)
        {
            rez_no[ss][o]=rastgele_rez_no[o];
        }
        ss++;

    printf("Rezervasyon Numaraniz(Bu Numarayi Saklayiniz): ");
    for(c=cc-1;c<100;c++)
    {
        for(d=0;d<8;d++)
        {
            printf("%c",rez_no[c][d]);
        }
        musteri_menu();
    }

}

void rezervasyon_goster()//bilet fiyatina bak
{
    printf("Rezervasyon Numaranizi Giriniz: ");
    scanf("%s",&istenilen_rez_no);
    for(a=0;a<100;a++)
    {
        if(strcmp(istenilen_rez_no , rez_no[a]))
        {
            //bÝLET FÝYATÝ EKLE

            for(dd=0;dd<strlen(ad[seferno_secim3]);dd++)
            {
                printf("%c",ad[seferno_secim3][dd]);
            }
            printf(" ");
            for(dd=0;dd<strlen(ad[seferno_secim3]);dd++)
            {
                printf("%c",soyad[seferno_secim3][dd]);
            }
            printf(" %d ",koltuk_secim[seferno_secim3]);


            printf(" %d Nolu Otobus ile ",secim_otobusno[seferno_secim3]);
            printf("%s Sehrinden ",sehir_baslangic[seferno_secim3+1]);
            printf("%s Sehrine ",sehir_varis[seferno_secim3+1]);
            printf("%d-%d Saatleri Arasinda ",baslangic_saati_saat[seferno_secim3+1],bitis_saati[seferno_secim3+1]);
            printf("Yolculuk Gerceklestirilecektir\n");
            musteri_menu();
        }
    }
    printf("Hatali Rezervasyon Numarasi Girdiniz!!");
    rezervasyon_goster();
}













void ana_menu();
void firma_menu();
void firma_menu_otobusekle();
void firma_menu_seferbilgiekle();
void seferbilgi_sefer_noekle();
void firma_menu_seferbilgisi_otobusno();
void sefer_baslangic_saati();
void sefer_bitis_saati();
void sehir_1();
void sehir_2();
void istenilen_hasilat();
void firma_menu_koltuk();
void koltuk_bilgisi();
void bilgilendirme();
void musteri_menu();
void musteri_menu_seferlistele();
void musteri_menu_rezervasyon_yap();
void rezervasyon_koltuk_satin_alma();
void rezervasyon_no_olusturma();
void rezervasyon_goster();

int main()
{


    ana_menu();


    return 0;
}

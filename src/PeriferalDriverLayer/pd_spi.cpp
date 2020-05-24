#include <stdint.h>
#include "pd_spi.h"
#include "iodefine.h"


//8bitフリーランニングカウンタとして動作
//TMR0をSPI受信時の待ち時間生成に利用

namespace periferal_driver {
    void initTMR0() {
        SYSTEM.PRCR.WORD = 0xA502;
        SYSTEM.MSTPCRA.BIT.MSTPA5 = 0; //TMR0と1 ON
        SYSTEM.PRCR.WORD = 0xA500;

        TMR0.TCCR.BIT.CSS = 1; //1:PCLKBをカウントソースに設定
        TMR0.TCCR.BIT.CKS = 0; //0:分周比1
        TMR0.TCSTR.BIT.TCS = 1; //1:カウント開始 0:カウンタストップ
    }

    void initRSPI0() {
        int dummy;
        SYSTEM.PRCR.WORD = 0xA502;
        MSTP(RSPI0) = 0; //モジュールストップを解除
        SYSTEM.PRCR.WORD = 0xA500;

        //各ピンをSPIに割り付け
        PORTA.PMR.BIT.B4 = 0; //ピンの設定をするときはまずピンを汎用ポートに設定しておく
        PORTA.PMR.BIT.B5 = 0;
        PORTA.PMR.BIT.B6 = 0;
        PORTA.PMR.BIT.B7 = 0;
        PORTA.PMR.BIT.B0 = 0;

        MPC.PWPR.BIT.B0WI = 0; //書き込み許可 0で許可
        MPC.PWPR.BIT.PFSWE = 1; //書き込み許可  1で許可
        MPC.PA4PFS.BIT.PSEL = 0b001101; //SSLA0に設定
        MPC.PA0PFS.BIT.PSEL = 0b001101; //SSLA1に設定

        MPC.PA5PFS.BIT.PSEL = 0b001101; //RSPCKAに設定
        MPC.PA6PFS.BIT.PSEL = 0b001101; //MOSIAに設定
        MPC.PA7PFS.BIT.PSEL = 0b001101; //MISOAに設定
        MPC.PWPR.BIT.PFSWE = 0; //PFSWEの書き込み禁止 0
        MPC.PWPR.BIT.B0WI = 1; //書き込み禁止

        PORTA.PMR.BIT.B4 = 1; //ピンの設定をするときはまずピンを汎用ポートに設定しておく
        PORTA.PMR.BIT.B5 = 1;
        PORTA.PMR.BIT.B6 = 1;
        PORTA.PMR.BIT.B7 = 1;
        PORTA.PMR.BIT.B0 = 1;

        RSPI0.SPDCR.BIT.SPLW = 1; //SPDRレジスタへはロングアクセス

        //RSPIビットレートレジスタ(SPBR): 通常のシリアル通信と同様に設定する
        //ビットレート = f(PCLKA)/[2 × (n + 1) × 2^N]
        //mpu9250は1MHzまでOK
        //icm20608gは8MHzまでOK
        RSPI0.SPBR = 5; //8MHz
        //RSPI0.SPBR = 20; //2MHz

        //RSPI制御レジスタ(SPCR)
        RSPI0.SPCR.BIT.SPMS = 0;
        RSPI0.SPCR.BIT.TXMD = 0;

        //RSPIコマンドレジスタ(SPCMDx): 送受信フォーマットの設定
        RSPI0.SPCMD0.BIT.BRDV = 0;
        RSPI0.SPCMD0.BIT.CPHA = 1;
        RSPI0.SPCMD0.BIT.CPOL = 1;
        RSPI0.SPCMD0.BIT.SSLA = 0; //0:SSL0 1:SSL1
        RSPI0.SPCMD0.BIT.SSLKP = 1;
        RSPI0.SPDCR.BIT.SPFC = 0b00; //バッファのフレーム数を指定

        RSPI0.SPDCR.BIT.SPRDTD = 0; //受信バッファを読み出す
        RSPI0.SPCR.BIT.MSTR = 1;
        dummy = RSPI0.SPCR.BIT.MSTR;

        initTMR0();
    }

    void useSSLA0RSPI0() {
        setEnableRSPI0(0);
        RSPI0.SPBR = 5; //8MHz
        RSPI0.SPCMD0.BIT.SSLA = 0; //0:SSL0 1:SSL1
        RSPI0.SPCMD0.BIT.SPB = 0b0111;
    }

    void useSSLA1RSPI0() {
        setEnableRSPI0(0);
        RSPI0.SPCMD0.BIT.SSLA = 1; //0:SSL0 1:SSL1
        RSPI0.SPBR = 20; //2MHz
        RSPI0.SPCMD0.BIT.SPB = 0b1111;

    }


    uint8_t communicate8bitRSPI0(uint8_t transmit) {
        unsigned int receive;
        RSPI0.SPDR.LONG = (uint8_t) transmit;
        while(RSPI0.SPSR.BIT.SPTEF != 1) {
        };
        while (RSPI0.SPSR.BIT.SPRF == 0) {
        }
        receive = RSPI0.SPDR.LONG;
        return (uint8_t) (receive & 0xff);
    }

    uint16_t communicate16bitRSPI0(uint16_t transmit) {
        setEnableRSPI0(0);
        setEnableRSPI0(1);
        uint32_t receive;
        RSPI0.SPDR.LONG = (uint16_t) transmit;
        while(RSPI0.SPSR.BIT.SPTEF == 0) {} //送信完了待ち
        while(RSPI0.SPSR.BIT.SPRF == 0) {} //データ受信待ち

        receive = RSPI0.SPDR.LONG;

        return (uint16_t) (receive & 0xffff);
    }

    uint8_t communicate8bitRSPI1(uint8_t transmit) {
        unsigned int receive;
        RSPI1.SPDR.LONG = transmit;
        //  myprintf3("---------%x\n",transmit);
        //while(RSPI1.SPSR.BIT.SPTEF != 1);
        while (RSPI1.SPSR.BIT.SPRF == 0) {
            //      myprintf3("SPRF 0\n");
        };
        receive = RSPI1.SPDR.LONG;
        //while(RSPI1.SPSR.BIT.SPRF == 1){
        //  myprintf3("SPRF 1\n");

        //};
        //  myprintf3("rec %d\n",RSPI1.SPDR.LONG);
        return (uint8_t) (receive & 0xff);
    }

    void setEnableRSPI0(uint8_t en) {
        RSPI0.SPCR.BIT.SPE = en;
    }

    void setEnableRSPI1(uint8_t en) {
        RSPI1.SPCR.BIT.SPE = en;
    }

    void initRSPI1() {
        int dummy;

        SYSTEM.PRCR.WORD = 0xA502;
        MSTP(RSPI1) = 0; //モジュールストップを解除
        SYSTEM.PRCR.WORD = 0xA500;

        //各ピンをSPIに割り付け
        PORTE.PMR.BIT.B4 = 0; //ピンの設定をするときはまずピンを汎用ポートに設定しておく
        PORTE.PMR.BIT.B5 = 0;
        PORTE.PMR.BIT.B6 = 0;
        PORTE.PMR.BIT.B7 = 0;

        MPC.PWPR.BIT.B0WI = 0; //書き込み許可 0で許可
        MPC.PWPR.BIT.PFSWE = 1; //書き込み許可  1で許可
        MPC.PE4PFS.BIT.PSEL = 0b001101; //SSLB0に設定
        MPC.PE5PFS.BIT.PSEL = 0b001101; //RSPCKBに設定
        MPC.PE6PFS.BIT.PSEL = 0b001101; //MOSIBに設定
        MPC.PE7PFS.BIT.PSEL = 0b001101; //MISOBに設定
        MPC.PWPR.BIT.PFSWE = 0; //PFSWEの書き込み禁止 0
        MPC.PWPR.BIT.B0WI = 1; //書き込み禁止

        PORTE.PMR.BIT.B4 = 1; //ピンの設定をするときはまずピンを汎用ポートに設定しておく
        PORTE.PMR.BIT.B5 = 1;
        PORTE.PMR.BIT.B6 = 1;
        PORTE.PMR.BIT.B7 = 1;

        RSPI1.SPDCR.BIT.SPLW = 1; //SPDRレジスタへはロングアクセス

        //RSPIビットレートレジスタ(SPBR): 通常のシリアル通信と同様に設定する
        //ビットレート = f(PCLKA)/[2 × (n + 1) × 2^N]
        //mpu9250は1MHzまでOK
        //icm20608gは8MHzまでOK
        RSPI1.SPBR = 47;
        //RSPI制御レジスタ(SPCR)
        RSPI1.SPCR.BIT.SPMS = 0;
        RSPI1.SPCR.BIT.TXMD = 0;

        //RSPIコマンドレジスタ(SPCMDx): 送受信フォーマットの設定
        RSPI1.SPCMD0.BIT.BRDV = 0;
        RSPI1.SPCMD0.BIT.CPHA = 1;
        RSPI1.SPCMD0.BIT.CPOL = 1;
        RSPI1.SPCMD0.BIT.SSLA = 0;
        RSPI1.SPCMD0.BIT.SSLKP = 1;
        RSPI1.SPDCR.BIT.SPFC = 0b00; //バッファのフレーム数を指定

        RSPI1.SPDCR.BIT.SPRDTD = 0; //受信バッファを読み出す
        RSPI1.SPCR.BIT.MSTR = 1;
        dummy = RSPI1.SPCR.BIT.MSTR;

        initTMR0();

    }

    void communicateNbyteRSPI0(uint8_t* send, uint8_t* recv, uint8_t num) {
        setEnableRSPI0(1);
        for (int i = 0; i < num; i++) {
            //1byte受信するたびにちょっと待ち時間が必要
            uint32_t dummy = TMR0.TCNT;
            while (dummy == TMR0.TCNT);


            recv[i] = communicate8bitRSPI0(send[i]);
        }
        setEnableRSPI0(0);
    }

    void communicateNbyteRSPI1(uint8_t* send, uint8_t* recv, uint8_t num) {
        setEnableRSPI1(1);
        for (int i = 0; i < num; i++) {

            //1byte受信するたびにちょっと待ち時間が必要
            uint32_t dummy = TMR0.TCNT;
            while (dummy == TMR0.TCNT);
            recv[i] = communicate8bitRSPI1(send[i]);
        }
        setEnableRSPI1(0);
    }
}

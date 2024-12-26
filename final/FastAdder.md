# 快速加法器波形模擬|學習筆記

## 簡介
快速加法器（FastAdder）是一種高效的電路，用於執行二進制加法。本次作業目的是學習如何設計、實現並測試快速加法器模組，使用 Verilog 語言在 Quartus 環境中完成波形模擬。

## 學習目標

1. 實現一個快速加法器，對兩個二進位數進行加法運算。
2. 學習使用Quartus進行波形模擬。

## 設計說明
![image](https://github.com/user-attachments/assets/94efc12f-214d-41e7-8dbc-d69c66918b9c)

- **輸入**：
  - `A`：n 位二進制輸入。
  - `B`：n 位二進制輸入。
  - `Cin`：進位輸入位。
- **輸出**：
  - `Sum`：n 位和輸出。
  - `Cout`：進位輸出位。
- **位寬**：位寬(n)為參數化，默認為4位。

## Verilog 實現

以下是快速加法器模組的 Verilog 代碼：

```FastAdder.v
module FastAdder (
    input [3:0] A,  // 4-bit input A
    input [3:0] B,  // 4-bit input B
    input Cin,      // Carry input
    output [3:0] Sum, // 4-bit Sum output
    output Cout      // Carry output
);
    wire [3:0] G;   // Generate signals
    wire [3:0] P;   // Propagate signals
    wire [3:0] C;   // Carry signals

    // Generate and Propagate
    assign G = A & B;        // Generate
    assign P = A ^ B;        // Propagate

    // Carry calculation
    assign C[0] = Cin;
    assign C[1] = G[0] | (P[0] & C[0]);
    assign C[2] = G[1] | (P[1] & C[1]);
    assign C[3] = G[2] | (P[2] & C[2]);

    // Sum calculation
    assign Sum = P ^ C[3:0];
    assign Cout = G[3] | (P[3] & C[3]);

endmodule

```


```FastAdder_tb.v
module FastAdder_tb;
    reg [3:0] A, B;
    reg Cin;
    wire [3:0] Sum;
    wire Cout;

    // Instantiate the FastAdder
    FastAdder uut (
        .A(A),
        .B(B),
        .Cin(Cin),
        .Sum(Sum),
        .Cout(Cout)
    );

    initial begin
        // Test cases
        A = 4'b0001; B = 4'b0010; Cin = 0; #10; // 1 + 2
        A = 4'b0111; B = 4'b0001; Cin = 0; #10; // 7 + 1
        A = 4'b1111; B = 4'b1111; Cin = 1; #10; // 15 + 15 + 1
        $stop;
    end
endmodule
```

## Quartus 實現步驟

1. **創建新項目**：

   - 打開 Quartus，創建一個名為 `FastAdder` 的新項目。
   - 將 Verilog 文件（`FastAdder.v` 和 `FastAdder_tb.v`）添加到項目中。

2. **編譯設計**：

   - 點擊 "Processing > Start Compilation"。
   - 確保編譯報告中沒有錯誤。

3. **模擬設計**：

   - 使用ModelSim模擬工具。
   - 運行測試平台（`FastAdder_tb`），並觀察波形結果。
   - 驗證`Sum` 和 `Cout`是否符合預期。

4. **綜合設計**：

   - 指定目標 FPGA 設備並綜合設計。
   - 分析資源利用率和時序報告。

## 波形模擬圖
![alt text](image-5.png)

>input A
![alt text](image-1.png)
>input B
![alt text](image.png)
>Cin
![alt text](image-2.png)
>Sum
![alt text](image-3.png)
>Cout
![alt text](image-4.png)
## 結論

快速加法器模組是一個簡單但高效的二進制加法實現。其設計和測試為學習 Verilog 和 Quartus 數字電路設計提供了基礎。

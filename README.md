# Linear-Transformation and differential

## Project Overview (專案概述)

本專案的核心目標在於**連結大一所學的「線性代數」與「微積分」**。

有別於傳統常見以字串解析或字元搜尋實作的微分程式，本專案從線性代數的視角出發，利用 C++ 將多項式抽象化為有限維度向量空間中的座標向量，並將微積分中的「微分算子」實體化為「Transformation Matrix」，使其成為矩陣乘法 $T(v) = Av$。

同時，本專案**以大一所學的各項微分公式（如乘法法則、除法法則、連鎖律）以及超越函數（如 $\cos, \log$）作為程式的 Boundaries 探討**。透過程式實作時所遭遇的限制，反思目前所學的不足之處。

---

## 預期的邊界探討
目前系統已具備處理普通的多項式微分，以下為預計要探討的微分法則

1. product rule
2. quotient rule
3. chain rule
4. derivative of inverse function
5. implict differentiation
6. transcendental function

---

## Dev Log / Changelog (開發更新日誌)

* **[2026-05-18] Initial Release**
  * 建立專案核心架構。
  * 完成以 Transformation Matrix 執行基礎微分運算的 C++ 核心演算法。
  * 確立未來 的 Boundary 的探討藍圖。
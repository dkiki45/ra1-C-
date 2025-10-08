# 🍽️ Food Composition Analyzer (C Project)

## 📖 About the Project
This project was developed for the **Imperative Programming** course, under **Prof. Alcides Calsavara**, as part of the **RA1 assignment**.  
Its main goal is to analyze nutritional data from the [Tabela Brasileira de Composição de Alimentos (TACO)](https://www.cfn.org.br/wp-content/uploads/2017/03/taco_4_edicao_ampliada_e_revisada.pdf) using the C programming language.

The program reads a `.csv` file containing 100 food items and provides an interactive menu that allows users to list, filter, and sort data based on nutritional values such as **energy**, **humidity**, **protein**, and **carbohydrates**.

---

## ⚙️ Features
- ✅ Read and store data from a CSV file using `struct`
- ✅ Manage food categories with `typedef enum`
- ✅ List foods alphabetically (`strcmp`)
- ✅ Sort foods using **Bubble Sort**
- ✅ Filter by:
  - Category
  - Highest humidity (%)
  - Highest energy (kcal)
  - Highest protein (g)
  - Highest carbohydrate (g)
  - Highest Energy/Protein ratio
  - Highest Energy/Carbohydrate ratio
- ✅ Modularized with multiple functions for clarity
- ✅ Interactive terminal menu with nested options

---

## 📂 Data Format
Each row of the `alimentos.csv` file follows this structure:
- numero,descricao,umidade,energia,proteina,carboidrato,categoria
- Example:
- ***1,	Arroz integral cozido,	70.1,	124,	2.6,	25.8,	1***

---

# 🧠 Core Concepts Implemented

- File handling with `fopen`, `fscanf`, and `fclose`
- String comparison with `strcmp`
- Sorting with **Bubble Sort**
- Dynamic filtering by category
- User-driven input and validation (`scanf`)
- Separation of logic into modular functions

# 🧮 Program Flow

1. Load and parse the `alimentos.csv` file
2. Store data into a vector of `struct Alimento`
3. Display the **Main Menu**
4. User selects a category
5. Show **Category Menu** with filtering/sorting options
6. Display formatted results on the terminal
7. Loop until user exits

# ▶️ To Run:
- gcc leitura_arquivo -o leitura_arquivo
- ./leitura_arquivo


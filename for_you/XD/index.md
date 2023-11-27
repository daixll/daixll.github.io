---
html:
    toc: true   # 打开侧边目录
export_on_save:
    html: true  # 自动保存
---

* Ubuntu `20.04.6`
* Python `3.8`
* GCC `9.4.0`
* NUPACK `4.0.1.8`
* Rosetta `rosetta.binary.ubuntu.release-362.tar.bz2`
    * SCons `4.5.2`
* rDock `23.11.97_ubuntu-20.04_g++_x86_64`

<br>

* run_3dRNA_DNA `-`（暂时未用）
* PyRosetta4 `pyrosetta-2023.47+release.5fe66cd241a-cp38-cp38-linux_x86_64.whl` （暂时未用）
* vscode `1.84.2`（可选）


## NUPACK

**用于核酸结构预测和热力学性质计算，输出二维结构** [下载](https://nupack.org/download/overview) / [文档](https://docs.nupack.org/)

* 安装
    1. 创建虚拟环境

        ```bash
        conda create -n XD python=3.8
        ```

    2. 安装依赖软件
        
        ```bash
        source activate # 可能需要先激活环境
        ```
        ```
        conda activate XD
        conda install numpy scipy pip matplotlib pandas jupyterlab
        ```

    3. 安装 `NUPACK`

        ```bash
        python3 -m pip install -U nupack -f ./nupack-4.0.1.8/package
        ```

**Utilities example**

* 输入

    * Sequence（核酸序列），形如 `ACGT...`
    * Structure Constraints（结构约束），？
    * Temperature（温度），
    * Ion Concentration（离子浓度），
    * ...

* 输出
    * **序列** `AUCG...`
    * **二级结构** `((...))`


```py
from nupack import *

my_model = Model(material='dna', celsius=37)
'''
meterial:
    dna (*)
    rna
celsius(摄氏度):
    37 (*)
'''

# Define walker sequences
walker_seq = ['augcugcccccugugugaagca']

# Define intended walker structure 
walker_struc = '(20.23+.23)20'

# Suboptimal proxy structures and energies
my_subopt = subopt(strands=walker_seq, model=my_model, energy_gap=1.1)


# Print out seq
#for i in walker_seq:
#    print(i)

# Print out components of the result for the given complex
print('\nSuboptimal proxy structure(s):\n\nseq: ', walker_seq[0])

for i, s in enumerate(my_subopt):
    print('    %2d: %s (%.2f kcal/mol)' % (i, s.structure, s.energy))
```


<br>

---

## Rosetta

**123** [注册](https://els2.comotion.uw.edu/product/rosetta) / [下载](https://www.rosettacommons.org/software/license-and-download) / [文档](https://www.rosettacommons.org/docs/latest/Home)


* 安装
    1. 解压缩
        ```bash
        tar -xvjf rosetta.binary.ubuntu.release-362.tar.bz2
        ```
    2. 下载构建工具 [SCons](https://scons.org/pages/download.html)
        
        1. 解压缩
            ```bash
            tar -zxvf scons-4.5.2.tar.gz
            ```
        2. 安装
            ```bash
            cd scons-4.5.2
            python setup.py install
            ```
        3. 验证
            ```bash
            scons --version
            ```
    3. 下载依赖
        ```bash
        sudo apt-get install lib32z1-dev
        ```    
    4. 构建
        ```bash
        cd rosetta.binary.ubuntu.release-362/main/source
        ./scons.py -j8 mode=release bin
        ```

**farfar2**

* 输入
    * **序列** `AUCG...`
    * **二级结构** `((...))`

* 输出
    * 三级结构（`.pdb`）

```sh
/home/jiao/Desktop/'rosetta.binary.ubuntu.release-362'/main/source/bin/rna_denovo.linuxgccrelease -sequence "ucaggu aagcag" -secstruct "(....( )....)" -nstruct 2 -out:file:silent test.out -minimize_rna -dump
```

<br>

---

## rDock

**预测小分子与蛋白质或其他生物分子的结合方式和结合能力** [下载](https://rdock.github.io/download/) / [文档](https://rdock.github.io/documentation/html_docs/index.html)



<br>

* **安装**

    1. 下载依赖
        ```bash
        sudo apt install -y make git libpopt0 libpopt-dev g++
        ```
    2. 下载 rDock 及构建
        ```bash
        git clone https://github.com/CBDD/rDock
        cd rDock
        make
        ```
    3. 验证
        ```bash
        cd bin
        ./rbcavity -help
        ```

**输入**

* 蛋白质结构（`.pdb`）
* 小分子结构（`.mol2`）
* 评分函数
* ...

**输出**

* 分子对接结果
* 评分信息

<br>

---


## PyRosetta4

**对蛋白质进行结构预测、分子对接、蛋白质设计等** [注册](https://els2.comotion.uw.edu/product/rosetta) / [下载](https://graylab.jhu.edu/download/PyRosetta4/archive/release/) / [文档](https://www.pyrosetta.org/documentation)


* 安装

    1. 进入虚拟环境
        ```bash
        conda activate XD
        ```
    2. 安装
            
        ```bash
        pip install pyrosetta-2023.47+release.5fe66cd241a-cp38-cp38-linux_x86_64.whl
        ```


**输入**

* 蛋白质结构（`.pdb`）
* 评分函数
* 任务定义

**输出**

* 优化后的蛋白质结构（`.pdb`）
* 评分信息
* ...

<br>

---


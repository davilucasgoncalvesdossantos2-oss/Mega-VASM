#!/data/data/com.termux/files/usr/bin/bash

# =========================
# SGDK AUTO BUILD (TERMUX)
# =========================

echo "== SGDK BUILD START =="

export SGDK=$HOME/SGDK
export RESCOMP="java -jar $SGDK/bin/rescomp.jar"

echo "[1] Compilando resources..."
$RESCOMP res/resources.res
if [ $? -ne 0 ]; then
    echo "ERROR: resources failed"
    exit 1
fi

echo "[2] Compilando jogo..."
make
if [ $? -ne 0 ]; then
    echo "ERROR: build failed"
    exit 1
fi

echo "== BUILD COMPLETO =="
echo "ROM gerada em out/ ou raiz do projeto"
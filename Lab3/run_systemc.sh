#!/bin/bash

# --- Configurazione ---
SYSTEMC_LIB_PATH="/usr/local/systemc-3.0.1/lib-linux64"

# --- Controllo Argomenti ---
if [ -z "$1" ]; then
    echo "ERRORE: Devi specificare la sottodirectory del lab come argomento."
    echo "Utilizzo: ./run_lab.sh <nome_subdir>"
    exit 1
fi

# Variabile per la directory di destinazione
LAB_DIR="$1"

# --- Esecuzione ---

# 1. Naviga nella sottodirectory
echo "--- Entro in: $LAB_DIR ---"
if ! cd "$LAB_DIR"; then
    echo "ERRORE: Impossibile trovare o accedere alla directory $LAB_DIR."
    exit 1
fi

# 2. Esegue make clean e make
echo "--- Eseguo make clean e make ---"
make clean
# Verifica che make sia eseguito correttamente
if ! make; then
    echo "ERRORE: La compilazione (make) non è riuscita in $LAB_DIR."
    # Torna indietro prima di uscire
    cd - > /dev/null
    exit 1
fi

# 3. Imposta LD_LIBRARY_PATH ed esegue il programma
echo "--- Eseguo ./run.x con LD_LIBRARY_PATH temporaneo ---"
# L'impostazione di LD_LIBRARY_PATH qui è TEMPORANEA e vale solo per ./run.x
LD_LIBRARY_PATH="$SYSTEMC_LIB_PATH:$LD_LIBRARY_PATH" ./run.x

# 4. Torna alla directory originale (Importante!)
cd - > /dev/null

#echo "--- Esecuzione completata in $LAB_DIR ---"

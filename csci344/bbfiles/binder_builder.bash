file=$1
out=$2

#filename=$(echo "$file" | cut -f1 -d".")
#tar -xzf "$file"

line=$(head -n 1 "$file")
#dir=$(dirname "$file")
dir="."
num=0

if [ -d "$dir/temp_binder" ]; then
    rm -r "$dir/temp_binder"
fi
mkdir "$dir/temp_binder"

while read -r line
do

    num=$[num + 1]
    if [[ $line == "titlepage"* ]]; then
        line2=${line##"titlepage "}
        figlet "$line2" > "$dir/temp_binder/text_$num"

    elif [[ $line == "http://"* ]]; then
        links -dump "$line" > "$dir/temp_binder/text_$num"

    elif [[ $line == *".pdf"* ]]; then
        cp "$dir/$line" "$dir/temp_binder/pdf_ps_text_$num"

    elif [[ $line != "" ]]; then
        cp "$dir/$line" "$dir/temp_binder/text_$num"

    else
        num=$[num - 1]

    fi;

done < "$file"

for f in $dir/temp_binder/*
do
    dirn=$(basename "$f")
    dirm=$(dirname "$f")
    if [[ $dirn != "pdf_"* ]]; then
        enscript -B -q "$f" -p "$dirm/ps_$dirn"
        rm $f
    fi
done

for f in $dir/temp_binder/*
do
    dirn=$(basename "$f")
    dirm=$(dirname "$f")
    if [[ $dirn != "pdf_"* ]]; then
        ps2pdf "$f" "$dirm/pdf_$dirn"
        rm $f
    fi
done

#cd $dir
cd temp_binder

num=0
LIST=()
for f in *
do
    num=$[num + 1]
    LIST+=("pdf_ps_text_$num")
done


gs -dBATCH -dNOPAUSE -q -sDEVICE=pdfwrite -sOutputFile=../$out/finished.pdf "${LIST[@]}"

cd ..

rm -r temp_binder





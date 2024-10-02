for i in *.jpg; do
	convert "$i" -resize 640X480 "$i"
done


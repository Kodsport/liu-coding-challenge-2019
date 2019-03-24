python3 rand.py > secret/01-rand.in
python3 rand.py > secret/02-rand.in
python3 rand.py > secret/03-rand.in
python3 rand.py > secret/04-rand.in
python3 rand.py > secret/05-rand.in
python3 rand.py > secret/06-rand.in
python3 rand.py > secret/07-rand.in
python3 rand.py > secret/08-rand.in
python3 rand.py > secret/09-rand.in
python3 rand.py > secret/10-rand.in
python3 careful.py > secret/11-careful.in
python3 careful.py > secret/12-careful.in
python3 careful.py > secret/13-careful.in
python3 careful.py > secret/14-careful.in
python3 careful.py > secret/15-careful.in
python3 careful.py > secret/16-careful.in
python3 careful.py > secret/17-careful.in
python3 careful.py > secret/18-careful.in
python3 careful.py > secret/19-careful.in
python3 careful.py > secret/20-careful.in

for x in secret/*.in; do python3 ../submissions/accepted/js.py < $x > `echo $x | cut -d. -f 1`.ans; done

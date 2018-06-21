make clean
make all

echo abcdefghijklmn > a

echo opqrstuvwxyz > b

./ft_tail > output.txt

./ft_tail -c 

./ft_tail -c a

./ft_tail -c " +7" a >> output.txt
./ft_tail -c " 7" a >> output.txt
./ft_tail -c " -7" a >> output.txt
./ft_tail -c "+7" a >> output.txt
./ft_tail -c "7" a >> output.txt
./ft_tail -c "-7" a >> output.txt

./ft_tail -c " +7 " a >> output.txt
./ft_tail -c " 7 " a >> output.txt
./ft_tail -c " -7 " a >> output.txt
./ft_tail -c "+7 " a >> output.txt
./ft_tail -c "7 " a >> output.txt
./ft_tail -c "-7 " a >> output.txt

./ft_tail -c " +7" a a >> output.txt
./ft_tail -c " 7" a a >> output.txt
./ft_tail -c " -7" a a >> output.txt
./ft_tail -c "+7" a a >> output.txt
./ft_tail -c "7" a a >> output.txt
./ft_tail -c "-7" a a >> output.txt

./ft_tail -c " +7 " a a >> output.txt
./ft_tail -c " 7 " a a >> output.txt
./ft_tail -c " -7 " a a >> output.txt
./ft_tail -c "+7 " a a >> output.txt
./ft_tail -c "7 " a a >> output.txt
./ft_tail -c "-7 " a a >> output.txt

./ft_tail -c " +7" a a b >> output.txt
./ft_tail -c " 7" a a b >> output.txt
./ft_tail -c " -7" a a b >> output.txt
./ft_tail -c "+7" a a b >> output.txt
./ft_tail -c "7" a a b >> output.txt
./ft_tail -c "-7" a a b >> output.txt

./ft_tail -c " +7 " a a b >> output.txt
./ft_tail -c " 7 " a a b >> output.txt
./ft_tail -c " -7 " a a b >> output.txt
./ft_tail -c "+7 " a a b >> output.txt
./ft_tail -c "7 " a a b >> output.txt
./ft_tail -c "-7 " a a b >> output.txt

./ft_tail -c " +7" a a b c a >> output.txt
./ft_tail -c " 7" a a b c a >> output.txt
./ft_tail -c " -7" a a b c a >> output.txt
./ft_tail -c "+7" a a b c a >> output.txt
./ft_tail -c "7" a a b c a >> output.txt
./ft_tail -c "-7" a a b c a >> output.txt

./ft_tail -c " +7 " a a b c a >> output.txt
./ft_tail -c " 7 " a a b c a >> output.txt
./ft_tail -c " -7 " a a b c a >> output.txt
./ft_tail -c "+7 " a a b c a >> output.txt
./ft_tail -c "7 " a a b c a >> output.txt
./ft_tail -c "-7 " a a b c a >> output.txt

./ft_tail -c " +7" c a a b c a >> output.txt
./ft_tail -c " 7" c a a b c a >> output.txt
./ft_tail -c " -7" c a a b c a >> output.txt
./ft_tail -c "+7" c a a b c a >> output.txt
./ft_tail -c "7" c a a b c a >> output.txt
./ft_tail -c "-7" c a a b c a >> output.txt

./ft_tail -c " +7 " c a a b c a >> output.txt
./ft_tail -c " 7 " c a a b c a >> output.txt
./ft_tail -c " -7 " c a a b c a >> output.txt
./ft_tail -c "+7 " c a a b c a >> output.txt
./ft_tail -c "7 " c a a b c a >> output.txt
./ft_tail -c "-7 " c a a b c a >> output.txt

./ft_tail -c " +0" a a b c a >> output.txt
./ft_tail -c " 0" a a b c a >> output.txt
./ft_tail -c " -0" a a b c a >> output.txt
./ft_tail -c "+0" a a b c a >> output.txt
./ft_tail -c "0" a a b c a >> output.txt
./ft_tail -c "-0" a a b c a >> output.txt

./ft_tail -c " +0 " a a b c a >> output.txt
./ft_tail -c " 0 " a a b c a >> output.txt
./ft_tail -c " -0 " a a b c a >> output.txt
./ft_tail -c "+0 " a a b c a >> output.txt
./ft_tail -c "0 " a a b c a >> output.txt
./ft_tail -c "-0 " a a b c a >> output.txt

tail > tail.txt

tail -c 

tail -c a

tail -c " +7" a >> tail.txt
tail -c " 7" a >> tail.txt
tail -c " -7" a >> tail.txt
tail -c "+7" a >> tail.txt
tail -c "7" a >> tail.txt
tail -c "-7" a >> tail.txt

tail -c " +7 " a >> tail.txt
tail -c " 7 " a >> tail.txt
tail -c " -7 " a >> tail.txt
tail -c "+7 " a >> tail.txt
tail -c "7 " a >> tail.txt
tail -c "-7 " a >> tail.txt

tail -c " +7" a a >> tail.txt
tail -c " 7" a a >> tail.txt
tail -c " -7" a a >> tail.txt
tail -c "+7" a a >> tail.txt
tail -c "7" a a >> tail.txt
tail -c "-7" a a >> tail.txt

tail -c " +7 " a a >> tail.txt
tail -c " 7 " a a >> tail.txt
tail -c " -7 " a a >> tail.txt
tail -c "+7 " a a >> tail.txt
tail -c "7 " a a >> tail.txt
tail -c "-7 " a a >> tail.txt

tail -c " +7" a a b >> tail.txt
tail -c " 7" a a b >> tail.txt
tail -c " -7" a a b >> tail.txt
tail -c "+7" a a b >> tail.txt
tail -c "7" a a b >> tail.txt
tail -c "-7" a a b >> tail.txt

tail -c " +7 " a a b >> tail.txt
tail -c " 7 " a a b >> tail.txt
tail -c " -7 " a a b >> tail.txt
tail -c "+7 " a a b >> tail.txt
tail -c "7 " a a b >> tail.txt
tail -c "-7 " a a b >> tail.txt

tail -c " +7" a a b c a >> tail.txt
tail -c " 7" a a b c a >> tail.txt
tail -c " -7" a a b c a >> tail.txt
tail -c "+7" a a b c a >> tail.txt
tail -c "7" a a b c a >> tail.txt
tail -c "-7" a a b c a >> tail.txt

tail -c " +7 " a a b c a >> tail.txt
tail -c " 7 " a a b c a >> tail.txt
tail -c " -7 " a a b c a >> tail.txt
tail -c "+7 " a a b c a >> tail.txt
tail -c "7 " a a b c a >> tail.txt
tail -c "-7 " a a b c a >> tail.txt

tail -c " +7" c a a b c a >> tail.txt
tail -c " 7" c a a b c a >> tail.txt
tail -c " -7" c a a b c a >> tail.txt
tail -c "+7" c a a b c a >> tail.txt
tail -c "7" c a a b c a >> tail.txt
tail -c "-7" c a a b c a >> tail.txt

tail -c " +7 " c a a b c a >> tail.txt
tail -c " 7 " c a a b c a >> tail.txt
tail -c " -7 " c a a b c a >> tail.txt
tail -c "+7 " c a a b c a >> tail.txt
tail -c "7 " c a a b c a >> tail.txt
tail -c "-7 " c a a b c a >> tail.txt

tail -c " +0" a a b c a >> tail.txt
tail -c " 0" a a b c a >> tail.txt
tail -c " -0" a a b c a >> tail.txt
tail -c "+0" a a b c a >> tail.txt
tail -c "0" a a b c a >> tail.txt
tail -c "-0" a a b c a >> tail.txt

tail -c " +0 " a a b c a >> tail.txt
tail -c " 0 " a a b c a >> tail.txt
tail -c " -0 " a a b c a >> tail.txt
tail -c "+0 " a a b c a >> tail.txt
tail -c "0 " a a b c a >> tail.txt
tail -c "-0 " a a b c a >> tail.txt

diff output.txt tail.txt > difffff.txt
# TI-proj-T4
The Silesian Technical University project created as part of the Internet Technologies subject.

Temat projektu nr 4: Narzędzie do organizacji podziałów podsieci IPv6.

Narzędzie tekstowe do przeglądania plików zawierających listę podziałów adresów IP na mniejsze podsieci. Przykład pliku wejściowego:

(Tutaj przykład dla IPv4, przerobić na IPv6)

>```157.158.0.0/16 Przydzial nr 1
>	157.158.1.0/24 Podsiec dla klienta X
>	157.158.2.0/24 Podsiec dla klienta Y
>	157.158.128.0/17 Przydzialy dla oddzialow
>		157.158.128.0/24 WOLNA
>		157.158.129.0/24 Oddzial 1
>		157.158.130.0/24 WOLNA
>		157.158.131.1/24 Oddzial 2
>212.106.160.0/20 Przydzial nr 2
>	212.106.160.0/21 Oddzial zdalny```
	
Po wczytaniu pliku program powinien weryfikować błędy, np przydział dla "Oddział 2" ma nieprawidłowy adres sieci. Takie błędy najlepiej jak by były naprawiane. Kolejny przykład błędu, to możliwe powtórzenia przydziałów, co powinno być sygnalizowane.

Wynik powinien zawierać poukładane w kolejności podsieci z wcięciami tak jak na przykładzie powyżej (czyli jeśli jakaś podsieć zawiera się w innej to powinno to być poukładane jak w przykładzie. Wynik powinien zawierać komentarze jakie są dopisane do podsieci. W wyniku dobrze by było też dorobić brakujące podsieci do wypełnienia podsieci nadrzędnej (tylko w przypadku, gdy istnieje jakaś podsieć zawierająca się w nadrzędnej), np:

>```212.106.160.0/20 Przydzial nr 2
>	212.106.160.0/21 Oddzial zdalny```
Powinno zostać rozwinięte do:

>```212.106.160.0/20 Przydzial nr 2
>	212.106.160.0/21 Oddzial zdalny
>	212.106.168.0/21 WOLNA```

>Project for The Silesian Technical University. 
>Implemented under Internet Technology. 
>Third party person can continue it.

# Connect 0 &ndash; `ping 0` のナゾ

Zenn の記事 “ping 0 のナゾ” で書いたプログラムです。
記事はこちら: https://zenn.dev/kusaremkn/articles/720e4931fc2e46

適当な UDP ソケットを作り、
IPv4 アドレス **0** に `connect()` した上で `getsockname()` するとループバックアドレスが得られます。
この現象はソケットを **0** に `connect()` しないと得られません。

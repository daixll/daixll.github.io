## setup

### linux

### windows

## use

```shell
openssl genpkey -out pri.pem -algorithm RSA -pkeyopt rsa_keygen_bits:2048
```

```shell
openssl pkey -in pri.pem -pubout -out pub.pem
```

## dev


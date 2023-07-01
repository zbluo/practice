package mycrypto

import (
	"crypto/aes"
	"crypto/cipher"
	"crypto/rand"
	"fmt"
	"io"
)

func AesTest() {
	plainText := "AB"
	fmt.Printf("Original Text %2d:         %s\n", len(plainText), plainText)
	// KEY
	keyByte := []byte("myverystrongpasswordo32bitlength")
	fmt.Printf("The 32-byte Key:          %s\n", keyByte)
	// CREATE A NONCE
	nonce := make([]byte, aes.BlockSize)
	io.ReadFull(rand.Reader, nonce)
	fmt.Printf("The Nonce:                %X\n\n", nonce)

	// CTR
	fmt.Printf("AES CTR Test, block size: %d\n", aes.BlockSize)
	ct := AesCTREnc(keyByte, nonce, plainText)
	fmt.Printf("Encrypted Text %2d:        %X\n", len(ct), ct)
	pt := AesCTRDec(keyByte, nonce, ct)
	fmt.Printf("Decrypted Text:           %s\n\n", pt)

	// GCM
	fmt.Printf("AES GCM Test, block size: %d\n", aes.BlockSize)
	ct = AesGCMEnc(keyByte, nonce[:12], plainText)
	fmt.Printf("Encrypted Text %2d:        %X\n", len(ct), ct)
	pt = AesGCMDec(keyByte, nonce[:12], ct)
	fmt.Printf("Decrypted Text:           %s\n\n", pt)
}

func AesCTREnc(keyByte []byte, nonce []byte, plainText string) []byte {
	cipherTextByte := make([]byte, len(plainText))

	// GET CIPHER BLOCK USING KEY
	block, _ := aes.NewCipher(keyByte)
	// GET CTR
	ctr := cipher.NewCTR(block, nonce)

	// ENCRYPT DATA
	ctr.XORKeyStream(cipherTextByte, []byte(plainText))
	return cipherTextByte
}

func AesCTRDec(keyByte []byte, nonce []byte, cipherText []byte) []byte {
	plainTextByte := make([]byte, len(cipherText))

	// GET CIPHER BLOCK USING KEY
	block, _ := aes.NewCipher(keyByte)
	// GET CTR
	ctr := cipher.NewCTR(block, nonce)

	// DECRYPT DATA
	ctr.XORKeyStream(plainTextByte, cipherText)
	return plainTextByte
}

func AesGCMEnc(keyByte []byte, nonce []byte, plainText string) []byte {
	block, _ := aes.NewCipher(keyByte)
	aesgcm, _ := cipher.NewGCM(block)
	ciphertext := aesgcm.Seal(nil, nonce, []byte(plainText), nil)
	return ciphertext
}

func AesGCMDec(keyByte []byte, nonce []byte, cipherText []byte) []byte {
	block, _ := aes.NewCipher(keyByte)
	aesgcm, _ := cipher.NewGCM(block)
	plainText, _ := aesgcm.Open(nil, nonce, cipherText, nil)
	return plainText
}

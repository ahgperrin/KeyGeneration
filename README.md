# Generate secp public key with private key

## Technology C and Python.

## To launch after git clone

  cd KeyGeneration
  git submodule init
  git submodule update

  make

## Using python
  ### Launch Python & import Key Class
      python3
      from KeyGeneration import Key
  ### Instanciate Key
      key = Key()
  ### Initialise Key with Private Key params
      key.initialize('4b8e29b9b0dddd58a709edba7d6df6c07ebdaf5653e325114bc5318c238f87f0')
  ### Return Private Key
      key.getPublicKey()
  ### Return Public Key
      key.getPrivateKey()

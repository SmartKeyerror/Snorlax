#!/bin/sh


setup_git() {
  git config --global user.email "SmartKeyerror@gmail.com"
  git config --global user.name "Travis CI"
}

commit_website_files() {
  git add .
  git commit --message ":robot: Travis build: $TRAVIS_BUILD_NUMBER"
}


upload_files() {
  git remote add origin https://${GH_TOKEN}@github.com/SmartKeyerror/Snorlax.git
  git push origin master
}

setup_git
commit_website_files
upload_files
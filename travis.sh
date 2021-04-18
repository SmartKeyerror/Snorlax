#!/bin/sh


setup_git() {
  git config --global user.email "travis@travis-ci.org"
  git config --global user.name "Travis CI"
  git config --global push.default simple
}

commit_website_files() {
  git add .
  git commit --message ":robot: Travis build: $TRAVIS_BUILD_NUMBER"
}


upload_files() {
  git push -f https://${GH_TOKEN}@github.com/SmartKeyerror/Snorlax.git
}

setup_git
commit_website_files
upload_files
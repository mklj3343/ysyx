SBT = sbt
SITE="runMain updown.add"
TEST= 'testOnly updown.AddModuleSpec'


.PHONY: clean compile package run test

clean:
	rm -rf target/ project/target/

run:
	$(SBT) $(SITE)

test:
	$(SBT) $(TEST)
